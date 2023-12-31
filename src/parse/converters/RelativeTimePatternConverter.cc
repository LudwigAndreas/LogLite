//
// Created by Ludwig Andreas on 22.07.2023.
//

#include "parse/converters/RelativeTimePatternConverter.h"
namespace s21::parse {

RelativeTimePatternConverter::RelativeTimePatternConverter(std::vector<
    String> &options) : PatternConverter(options) {
  name_ = "Relative time";
}

std::shared_ptr<PatternConverter> RelativeTimePatternConverter::newInstance(std::vector<String> options) {
  if (options.empty()) {
    static std::shared_ptr<PatternConverter> def = std::make_shared<RelativeTimePatternConverter>(options);
    return def;
  }
  return std::make_shared<RelativeTimePatternConverter>(options);
}

void RelativeTimePatternConverter::format(const LoggingEvent &event,
                                          String &to_append_to) const {
  time_t delta = (event.GetTimeStamp() - LoggingEvent::GetStartTime()) / 1000;
  to_append_to.append(std::to_string(delta));
}

}