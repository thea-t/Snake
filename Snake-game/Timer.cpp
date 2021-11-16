//#include <iostream>
//
//#include "Timer.h"
//
//Timer::Timer()
//{//starts straight AWay whhen the obj is instantiated
//	start();
//}
//
//void Timer::start()
//{
//	m_startTime = m_clock.now();
//}
//
//float Timer::getElapsedSeconds() 
//{
//	TimePoint currentTime = m_clock.now();
//	std::chrono::duration<float> elapsed_seconds = currentTime - m_startTime;
//
//	float elapsedSeconds = elapsed_seconds.count();
//
//	return elapsedSeconds;
//}