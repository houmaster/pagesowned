#pragma once

#include "common.h"
#include <filesystem>
#include <functional>

struct ArchiveFile {
  std::string url;
  uint64_t compressed_size;
  uint64_t uncompressed_size;
  time_t modification_time;
};

struct ArchiveHtml {
  std::string url;
  std::string_view html;
};

enum class HtmlSection {
  content,
  heading,
  title,
  navigation,
};

int64_t get_archive_uid(const std::filesystem::path& filename);
bool for_each_archive_file(const std::filesystem::path& filename,
  std::function<void(ArchiveFile)> file_callback);
bool for_each_archive_html(const std::filesystem::path& filename,
  std::function<void(ArchiveHtml)> file_callback);
void for_each_html_text(std::string_view html,
  std::function<void(std::string_view, HtmlSection)> text_callback);
