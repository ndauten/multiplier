// Copyright (c) 2022-present, Trail of Bits, Inc.
// All rights reserved.
//
// This source code is licensed in accordance with the terms specified in
// the LICENSE file found in the root directory of this source tree.

#pragma once

#include <memory>
#include <pasta/Util/FileManager.h>

namespace mx {
class DatalogClient;  // Auto-generated from Datalog.
class Executor;
class ProgressBar;
}  // namespace mx
namespace indexer {

class Context {
 private:
  Context(void) = delete;

 public:
  const mx::DatalogClient &client;
  const pasta::FileManager file_manager;
  std::unique_ptr<mx::ProgressBar> command_progress;
  std::unique_ptr<mx::ProgressBar> ast_progress;

  ~Context(void);
  Context(const mx::Executor &exe_, const mx::DatalogClient &client_);
};

}  // namespace indexer