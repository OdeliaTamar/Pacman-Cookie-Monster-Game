#pragma once
#include"Observer.h"
#include <vector>
#include <memory>
class Subject
{
public:
	Subject();
	virtual ~Subject()=default;
	virtual void registerObserver(Observer* observer);
	virtual void notifyObserversForLiveAndScore()=0;
protected:
	std::vector <Observer*> m_observers;
};
