class Time{
	public:
	Time();
	Time(int aHour, int aMin, int aSec);
	
	int gethour() const;
	int getmin() const;
	int getsec() const;
	int gettotal() const;
	
	void sethour(int aHour);
	void setmin(int aMin);
	void setsec(int aSec);
	
	void print(Time &time2) const;
	
	private:
	int hour;
	int min;
	int sec;
};

bool IsEarlierThan(const Time& t1, const Time& t2);