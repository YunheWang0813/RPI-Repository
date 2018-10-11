
// condition variables

#include <iostream>
#include <thread>
#include <mutex>

//  g++ -g -Wall -std=c++11 -o notetaker_a2  notetaker_a2.cpp -pthread 

#define Drawing int

// ==========================================
// ==========================================

class Chalkboard {
public:
  Chalkboard() {student_done = true; }
  void write(Drawing d) {
    while (1) {
      board.lock();
      if (student_done) {
	std::cout << "writing " << d << std::endl;
	drawing = d;
	student_done = false;
	board.unlock();
	return;
      }
      board.unlock();
    }
  }
    
  Drawing read() {
    while (1) {
      board.lock();
      if (!student_done) {
	Drawing answer = drawing;
	std::cout << "reading " << drawing << std::endl;
	student_done = true;
	board.unlock();
	return answer;
      }
      board.unlock();
    }
  }
  
private:
  Drawing drawing;
  std::mutex board;
  bool student_done;
};

// ==========================================

class  Professor {
public:
  Professor(Chalkboard *c) { 
    chalkboard = c; 
    next_lecture = 0; 
  }
  virtual bool Lecture() { 
    if (next_lecture > 100) return false;
    chalkboard->write(Drawing(next_lecture)); 
    next_lecture++; 
    return true;
  }
protected:
  Chalkboard* chalkboard;
  int next_lecture;
};

// ==========================================

class Student {
public:
  Student(Chalkboard *c) { chalkboard = c; notebook=0; }
  bool TakeNotes() { 
    if (notebook >= 100) return false;
    chalkboard->read();
    //    std::cout << chalkboard->read() << std::endl; 
    notebook++;
    return true;
  }
private:
  Chalkboard* chalkboard;
  int notebook;
};

// ==========================================
// ==========================================


#define num_lectures 10

void student_thread(Chalkboard *chalkboard) {
  Student student(chalkboard);
  for (int i = 0; i < num_lectures; i++) {
    student.TakeNotes();
  }
}




int main() {

  Chalkboard chalkboard;
  Professor prof(&chalkboard);
  std::thread student(student_thread, &chalkboard);
  for (int i = 0; i < num_lectures; i++) {
    prof.Lecture();
  }

   student.join();

  std::cout << "class dismissed!" << std::endl;
}