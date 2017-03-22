#pragma once

#include <thread>
#include <vector>

#include <shoom.h>

#include <capsule/messages.h>
#include <capsulerun.h>
#include <capsulerun_args.h>

#include "video_receiver.h"
#include "audio_receiver.h"
#include "session.h"
#include "connection.h"

namespace capsule {

typedef audio::AudioReceiver * (*audio_receiver_factory_t)();

class MainLoop {
  public:
    MainLoop(capsule_args_t *args, Connection *conn) :
      args_(args),
      conn_(conn)
      {};
    void Run(void);
    void CaptureFlip();

    audio_receiver_factory_t audio_receiver_factory_ = nullptr;

  private:
    void EndSession();
    void JoinSessions();

    void CaptureStart();
    void CaptureStop();
    void StartSession(const messages::VideoSetup *vs);

    capsule_args_t *args_;

    Connection *conn_;
    Session *session_ = nullptr;
    std::vector<Session *> old_sessions_;
};

} // namespace capsule