#ifndef time
#define time


class Time{
	public:
	Time();
	Time(uintptr_t aHour, uintptr_t aMin, uintptr_t aSec);
	
	uintptr_t gethour() const;
	uintptr_t getmin() const;
	uintptr_t getsec() const;
	
	void sethour(uintptr_t aHour);
	void setmin(uintptr_t aMin);
	void setsec(uintptr_t aSec);
	
	void print(Time &time2) const;
	
	private:
	uintptr_t hour;
	uintptr_t min;
	uintptr_t sec;
};

#endif