//
// Created by Ludwig Andreas on 22.07.2023.
//

#include "parse/converters/ThreadPatternConverter.h"
namespace s21::parse {

ThreadPatternConverter::ThreadPatternConverter(std::vector<String> &options)
    : PatternConverter(options) {
  name_ = "Thread name";
}

std::shared_ptr<PatternConverter> ThreadPatternConverter::newInstance(std::vector<String> options) {
  return std::make_shared<ThreadPatternConverter>(options);
}

void ThreadPatternConverter::format(const LoggingEvent &event,
                                                String &to_append_to) const {
to_append_to.append(event.GetThreadName());
}

}