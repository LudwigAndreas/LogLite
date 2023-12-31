//
// Created by Ludwig Andreas on 19.07.2023.
//

#ifndef S21_INCLUDE_LOGGER_PARSER_PATTERNLAYOUT_H_
#define S21_INCLUDE_LOGGER_PARSER_PATTERNLAYOUT_H_

#include <map>
#include <memory>

#include "parse/LoggingEvent.h"
#include "parse/PatternParser.h"
#include "logger_type.h"
#include "parse/converters/PatternConverter.h"
#include "parse/FormattingInfo.h"

namespace s21::diagnostic {
class PatternLayout {
 private:

  String conversion_pattern_;

  std::vector<std::shared_ptr<parse::PatternConverter>> pattern_converters_;

  std::vector<parse::FormattingInfo> pattern_fields_;

  String fatal_color_ = "\x1B[35m";
  String error_color_ = "\x1B[31m";
  String warn_color_ = "\x1B[33m";
  String info_color_ = "\x1B[32m";
  String debug_color_ = "\x1B[36m";
  String trace_color_ = "\x1B[34m";

 protected:

  void activateOptions();

  virtual s21::parse::PatternMap getFormatSpecifiers();

  std::shared_ptr<s21::parse::PatternConverter>createColorStartPatternConverter(const std::vector<
      String> &options);

  PatternLayout(const PatternLayout& other) = default;

  String ToLowerCase(String ref);

 public:
  PatternLayout();

  PatternLayout(PatternLayout&& other) = default;

  PatternLayout(String pattern);

  ~PatternLayout();

  PatternLayout& operator=(PatternLayout&& other) = default;

  PatternLayout& operator=(const PatternLayout& other) = delete;

  PatternLayout GetCopy();

  const std::vector<std::shared_ptr<parse::PatternConverter>> &GetPatternConverters() const;

  void setConversionPattern(const String &conversion_pattern);

  String getConversionPattern() const;

  void setOption(const String &option, const String &value);

  void format(String &output,
              const parse::LoggingEvent &event);

};
}

#endif //S21_INCLUDE_LOGGER_PARSER_PATTERNLAYOUT_H_
