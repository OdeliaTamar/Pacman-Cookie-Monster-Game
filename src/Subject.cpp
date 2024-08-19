#include "Subject.h"

Subject::Subject()
{
}
//------------------------------------
void Subject::registerObserver(Observer* observer)
{
	m_observers.push_back(observer);
}
