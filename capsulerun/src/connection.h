#pragma once

#include <capsule/messages.h>

class Connection {
  public:
    Connection(std::string &r_path, std::string &w_path);
    void connect();
    void printDetails();

    void write(const flatbuffers::FlatBufferBuilder &builder);
    char *read();

    void write_capture_start();

  private:
    std::string *r_path;
    std::string *w_path;
#if defined(LAB_WINDOWS)
    HANDLE pipe_r;
    HANDLE pipe_w;
#else // LAB_WINDOWS
    int fifo_r;
    int fifo_w;
#endif // !LAB_WINDOWS
};
