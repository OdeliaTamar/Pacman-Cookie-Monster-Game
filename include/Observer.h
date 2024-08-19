#pragma once

class Observer
{
public:
	Observer()=default;
	virtual ~Observer()=default;
	virtual  void updateLive(int lives) = 0;
	virtual  void updateScore(int score) = 0;
protected:

};
