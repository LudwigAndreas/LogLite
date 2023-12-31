//
// Created by Ludwig Andreas on 22.07.2023.
//

#include "parse/LoggingEvent.h"

#include <utility>
#include <thread>

#include "LoggerInitializer.h"

namespace s21::parse {

s21::diagnostic::LogLevel LoggingEvent::GetLevel() const {
  return level_;
}

const String &LoggingEvent::GetFileName() const {
  return file_;
}

int LoggingEvent::getLine() const {
  return line_;
}

const String &LoggingEvent::getLoggerName() const {
  return logger_name_;
}

const String &LoggingEvent::getMessage() const {
  return message_;
}

const String &LoggingEvent::GetMethodName() const {
  return method_;
}

const String &LoggingEvent::GetShortFileName() const {
  return short_file_name_;
}

const String LoggingEvent::GetThreadName() const {
  if (thread_name_.empty()) {
    return std::to_string(static_cast<int>(std::hash<std::thread::id>{}
        (std::this_thread::get_id())));
  }
  return thread_name_;

}

int LoggingEvent::GetPid() {
  return diagnostic::LoggerInitializer::GetPid();
}

time_t LoggingEvent::GetStartTime() {
  return diagnostic::LoggerInitializer::GetTime();
}

time_t LoggingEvent::GetTimeStamp() const {
  return time(nullptr);
}

const String LoggingEvent::getClassName() const {
  String tmp = method_;
  size_t paren_pos = tmp.find('(');

  if (paren_pos != String::npos) {
    tmp.erase(paren_pos);
  }
  size_t colon_pos = tmp.rfind("::");
  if (colon_pos != String::npos) {
    tmp.erase(colon_pos);
    size_t space_pos = tmp.find_last_of(' ');
    if (space_pos != String::npos) {
      tmp.erase(0, space_pos + 1);
    }
    return tmp;
  }
  tmp.erase(0, tmp.length());
  return tmp;
}

LoggingEvent::LoggingEvent(s21::diagnostic::LogLevel level,
                           String file,
                           String func_name,
                           int line,
                           String logger_name,
                           String message)
    : level_(level),
      file_(std::move(file)),
      line_(line),
      logger_name_(std::move(logger_name)),
      message_(std::move(message)),
      method_(func_name) {}

LoggingEvent::LoggingEvent() = default;

}