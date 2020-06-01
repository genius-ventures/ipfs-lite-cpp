#include "ipfs-lite/leveldb/leveldb_cursor.hpp"

#include "ipfs-lite/leveldb/leveldb_util.hpp"

namespace sgns::ipfs_lite {

  LevelDB::Cursor::Cursor(std::shared_ptr<leveldb::Iterator> it)
      : i_(std::move(it)) {}

  void LevelDB::Cursor::seekToFirst() {
    i_->SeekToFirst();
  }

  void LevelDB::Cursor::seek(const Buffer &key) {
    i_->Seek(make_slice(key));
  }

  void LevelDB::Cursor::seekToLast() {
    i_->SeekToLast();
  }

  bool LevelDB::Cursor::isValid() const {
    return i_->Valid();
  }

  void LevelDB::Cursor::next() {
    i_->Next();
  }

  void LevelDB::Cursor::prev() {
    i_->Prev();
  }

  Buffer LevelDB::Cursor::key() const {
    return make_buffer(i_->key());
  }

  Buffer LevelDB::Cursor::value() const {
    return make_buffer(i_->value());
  }

}  // namespace sgns::ipfs_lite