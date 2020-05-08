#include <chrono>
#include <iostream>
#include <sstream>
#include <windows.h>

using HighResTime = std::chrono::high_resolution_clock::time_point;

inline HighResTime nowHR()
{
  return std::chrono::high_resolution_clock::now();
}

inline double elapsedNanoSec(HighResTime startTime)
{
  return std::chrono::duration_cast<std::chrono::nanoseconds>(nowHR() - startTime).count();
}

inline double elapsedMicroSec(HighResTime startTime)
{
  return std::chrono::duration_cast<std::chrono::microseconds>(nowHR() - startTime).count();
}

inline std::string elapsedNanoSecStr(HighResTime startTime)
{
  double duration = elapsedNanoSec(startTime);
  // std::cout << duration << std::endl;
  std::ostringstream strs;
  strs << duration;
  return strs.str();
}

inline std::string elapsedMicroSecStr(HighResTime startTime)
{
  double duration = elapsedMicroSec(startTime);
  // std::cout << duration / 1000000 << std::endl;
  std::ostringstream strs;
  strs << duration;
  return strs.str();
}

class SlackTime
{
public:
  SlackTime()
      : m_duration("Not Available")
      , m_timeStamp()
      , m_isAvailable(false)
  {
  }
  void start() { m_isAvailable = true; m_timeStamp = nowHR(); }
  void stop() { m_duration = elapsedNanoSecStr(m_timeStamp); }
  std::string getDuration()
  {
    stop();
    if(m_isAvailable)
      return m_duration;
    else
      return "Not available";
    
  }

private:
  std::string m_duration;
  HighResTime m_timeStamp;
  bool        m_isAvailable;
};

int main()
{
  std::cout << "Hello\n";
  SlackTime slackTime;
  // slackTime.start();
  Sleep(500);
  
  std::cout << "Elapsed time " << slackTime.getDuration().c_str();
  return 0;
}