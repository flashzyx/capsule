// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_MESSAGES_CAPSULE_MESSAGES_H_
#define FLATBUFFERS_GENERATED_MESSAGES_CAPSULE_MESSAGES_H_

#include "flatbuffers/flatbuffers.h"

namespace capsule {
namespace messages {

struct Packet;

struct ReadyForYou;

struct SawBackend;

struct HotkeyPressed;

struct CaptureStart;

struct CaptureStop;

struct VideoSetup;

struct AudioSetup;

struct Shmem;

struct AudioFramesCommitted;

struct AudioFramesProcessed;

struct VideoFrameCommitted;

struct VideoFrameProcessed;

enum PixFmt {
  PixFmt_UNKNOWN = 0,
  PixFmt_RGBA = 1,
  PixFmt_BGRA = 2,
  PixFmt_RGB10_A2 = 3,
  PixFmt_YUV444P = 4,
  PixFmt_MIN = PixFmt_UNKNOWN,
  PixFmt_MAX = PixFmt_YUV444P
};

inline const char **EnumNamesPixFmt() {
  static const char *names[] = {
    "UNKNOWN",
    "RGBA",
    "BGRA",
    "RGB10_A2",
    "YUV444P",
    nullptr
  };
  return names;
}

inline const char *EnumNamePixFmt(PixFmt e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesPixFmt()[index];
}

enum SampleFmt {
  SampleFmt_UNKNOWN = 0,
  SampleFmt_U8 = 1,
  SampleFmt_S16 = 2,
  SampleFmt_S32 = 3,
  SampleFmt_F32 = 4,
  SampleFmt_F64 = 5,
  SampleFmt_MIN = SampleFmt_UNKNOWN,
  SampleFmt_MAX = SampleFmt_F64
};

inline const char **EnumNamesSampleFmt() {
  static const char *names[] = {
    "UNKNOWN",
    "U8",
    "S16",
    "S32",
    "F32",
    "F64",
    nullptr
  };
  return names;
}

inline const char *EnumNameSampleFmt(SampleFmt e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesSampleFmt()[index];
}

enum Backend {
  Backend_UNKNOWN = 0,
  Backend_GL = 1,
  Backend_D3D9 = 2,
  Backend_DXGI = 3,
  Backend_MIN = Backend_UNKNOWN,
  Backend_MAX = Backend_DXGI
};

inline const char **EnumNamesBackend() {
  static const char *names[] = {
    "UNKNOWN",
    "GL",
    "D3D9",
    "DXGI",
    nullptr
  };
  return names;
}

inline const char *EnumNameBackend(Backend e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesBackend()[index];
}

enum Message {
  Message_NONE = 0,
  Message_ReadyForYou = 1,
  Message_HotkeyPressed = 2,
  Message_CaptureStart = 3,
  Message_CaptureStop = 4,
  Message_VideoSetup = 5,
  Message_VideoFrameCommitted = 6,
  Message_VideoFrameProcessed = 7,
  Message_AudioFramesCommitted = 8,
  Message_AudioFramesProcessed = 9,
  Message_SawBackend = 10,
  Message_MIN = Message_NONE,
  Message_MAX = Message_SawBackend
};

inline const char **EnumNamesMessage() {
  static const char *names[] = {
    "NONE",
    "ReadyForYou",
    "HotkeyPressed",
    "CaptureStart",
    "CaptureStop",
    "VideoSetup",
    "VideoFrameCommitted",
    "VideoFrameProcessed",
    "AudioFramesCommitted",
    "AudioFramesProcessed",
    "SawBackend",
    nullptr
  };
  return names;
}

inline const char *EnumNameMessage(Message e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesMessage()[index];
}

template<typename T> struct MessageTraits {
  static const Message enum_value = Message_NONE;
};

template<> struct MessageTraits<ReadyForYou> {
  static const Message enum_value = Message_ReadyForYou;
};

template<> struct MessageTraits<HotkeyPressed> {
  static const Message enum_value = Message_HotkeyPressed;
};

template<> struct MessageTraits<CaptureStart> {
  static const Message enum_value = Message_CaptureStart;
};

template<> struct MessageTraits<CaptureStop> {
  static const Message enum_value = Message_CaptureStop;
};

template<> struct MessageTraits<VideoSetup> {
  static const Message enum_value = Message_VideoSetup;
};

template<> struct MessageTraits<VideoFrameCommitted> {
  static const Message enum_value = Message_VideoFrameCommitted;
};

template<> struct MessageTraits<VideoFrameProcessed> {
  static const Message enum_value = Message_VideoFrameProcessed;
};

template<> struct MessageTraits<AudioFramesCommitted> {
  static const Message enum_value = Message_AudioFramesCommitted;
};

template<> struct MessageTraits<AudioFramesProcessed> {
  static const Message enum_value = Message_AudioFramesProcessed;
};

template<> struct MessageTraits<SawBackend> {
  static const Message enum_value = Message_SawBackend;
};

bool VerifyMessage(flatbuffers::Verifier &verifier, const void *obj, Message type);
bool VerifyMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct Packet FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_MESSAGE_TYPE = 4,
    VT_MESSAGE = 6
  };
  Message message_type() const {
    return static_cast<Message>(GetField<uint8_t>(VT_MESSAGE_TYPE, 0));
  }
  const void *message() const {
    return GetPointer<const void *>(VT_MESSAGE);
  }
  template<typename T> const T *message_as() const;
  const ReadyForYou *message_as_ReadyForYou() const {
    return (message_type() == Message_ReadyForYou)? static_cast<const ReadyForYou *>(message()) : nullptr;
  }
  const HotkeyPressed *message_as_HotkeyPressed() const {
    return (message_type() == Message_HotkeyPressed)? static_cast<const HotkeyPressed *>(message()) : nullptr;
  }
  const CaptureStart *message_as_CaptureStart() const {
    return (message_type() == Message_CaptureStart)? static_cast<const CaptureStart *>(message()) : nullptr;
  }
  const CaptureStop *message_as_CaptureStop() const {
    return (message_type() == Message_CaptureStop)? static_cast<const CaptureStop *>(message()) : nullptr;
  }
  const VideoSetup *message_as_VideoSetup() const {
    return (message_type() == Message_VideoSetup)? static_cast<const VideoSetup *>(message()) : nullptr;
  }
  const VideoFrameCommitted *message_as_VideoFrameCommitted() const {
    return (message_type() == Message_VideoFrameCommitted)? static_cast<const VideoFrameCommitted *>(message()) : nullptr;
  }
  const VideoFrameProcessed *message_as_VideoFrameProcessed() const {
    return (message_type() == Message_VideoFrameProcessed)? static_cast<const VideoFrameProcessed *>(message()) : nullptr;
  }
  const AudioFramesCommitted *message_as_AudioFramesCommitted() const {
    return (message_type() == Message_AudioFramesCommitted)? static_cast<const AudioFramesCommitted *>(message()) : nullptr;
  }
  const AudioFramesProcessed *message_as_AudioFramesProcessed() const {
    return (message_type() == Message_AudioFramesProcessed)? static_cast<const AudioFramesProcessed *>(message()) : nullptr;
  }
  const SawBackend *message_as_SawBackend() const {
    return (message_type() == Message_SawBackend)? static_cast<const SawBackend *>(message()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_MESSAGE_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_MESSAGE) &&
           VerifyMessage(verifier, message(), message_type()) &&
           verifier.EndTable();
  }
};

template<> inline const ReadyForYou *Packet::message_as<ReadyForYou>() const {
  return message_as_ReadyForYou();
}

template<> inline const HotkeyPressed *Packet::message_as<HotkeyPressed>() const {
  return message_as_HotkeyPressed();
}

template<> inline const CaptureStart *Packet::message_as<CaptureStart>() const {
  return message_as_CaptureStart();
}

template<> inline const CaptureStop *Packet::message_as<CaptureStop>() const {
  return message_as_CaptureStop();
}

template<> inline const VideoSetup *Packet::message_as<VideoSetup>() const {
  return message_as_VideoSetup();
}

template<> inline const VideoFrameCommitted *Packet::message_as<VideoFrameCommitted>() const {
  return message_as_VideoFrameCommitted();
}

template<> inline const VideoFrameProcessed *Packet::message_as<VideoFrameProcessed>() const {
  return message_as_VideoFrameProcessed();
}

template<> inline const AudioFramesCommitted *Packet::message_as<AudioFramesCommitted>() const {
  return message_as_AudioFramesCommitted();
}

template<> inline const AudioFramesProcessed *Packet::message_as<AudioFramesProcessed>() const {
  return message_as_AudioFramesProcessed();
}

template<> inline const SawBackend *Packet::message_as<SawBackend>() const {
  return message_as_SawBackend();
}

struct PacketBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_message_type(Message message_type) {
    fbb_.AddElement<uint8_t>(Packet::VT_MESSAGE_TYPE, static_cast<uint8_t>(message_type), 0);
  }
  void add_message(flatbuffers::Offset<void> message) {
    fbb_.AddOffset(Packet::VT_MESSAGE, message);
  }
  PacketBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PacketBuilder &operator=(const PacketBuilder &);
  flatbuffers::Offset<Packet> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Packet>(end);
    return o;
  }
};

inline flatbuffers::Offset<Packet> CreatePacket(
    flatbuffers::FlatBufferBuilder &_fbb,
    Message message_type = Message_NONE,
    flatbuffers::Offset<void> message = 0) {
  PacketBuilder builder_(_fbb);
  builder_.add_message(message);
  builder_.add_message_type(message_type);
  return builder_.Finish();
}

struct ReadyForYou FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PIPE = 4
  };
  const flatbuffers::String *pipe() const {
    return GetPointer<const flatbuffers::String *>(VT_PIPE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PIPE) &&
           verifier.Verify(pipe()) &&
           verifier.EndTable();
  }
};

struct ReadyForYouBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_pipe(flatbuffers::Offset<flatbuffers::String> pipe) {
    fbb_.AddOffset(ReadyForYou::VT_PIPE, pipe);
  }
  ReadyForYouBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ReadyForYouBuilder &operator=(const ReadyForYouBuilder &);
  flatbuffers::Offset<ReadyForYou> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<ReadyForYou>(end);
    return o;
  }
};

inline flatbuffers::Offset<ReadyForYou> CreateReadyForYou(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> pipe = 0) {
  ReadyForYouBuilder builder_(_fbb);
  builder_.add_pipe(pipe);
  return builder_.Finish();
}

inline flatbuffers::Offset<ReadyForYou> CreateReadyForYouDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *pipe = nullptr) {
  return capsule::messages::CreateReadyForYou(
      _fbb,
      pipe ? _fbb.CreateString(pipe) : 0);
}

struct SawBackend FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_BACKEND = 4
  };
  Backend backend() const {
    return static_cast<Backend>(GetField<int32_t>(VT_BACKEND, 0));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_BACKEND) &&
           verifier.EndTable();
  }
};

struct SawBackendBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_backend(Backend backend) {
    fbb_.AddElement<int32_t>(SawBackend::VT_BACKEND, static_cast<int32_t>(backend), 0);
  }
  SawBackendBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  SawBackendBuilder &operator=(const SawBackendBuilder &);
  flatbuffers::Offset<SawBackend> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<SawBackend>(end);
    return o;
  }
};

inline flatbuffers::Offset<SawBackend> CreateSawBackend(
    flatbuffers::FlatBufferBuilder &_fbb,
    Backend backend = Backend_UNKNOWN) {
  SawBackendBuilder builder_(_fbb);
  builder_.add_backend(backend);
  return builder_.Finish();
}

struct HotkeyPressed FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           verifier.EndTable();
  }
};

struct HotkeyPressedBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  HotkeyPressedBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  HotkeyPressedBuilder &operator=(const HotkeyPressedBuilder &);
  flatbuffers::Offset<HotkeyPressed> Finish() {
    const auto end = fbb_.EndTable(start_, 0);
    auto o = flatbuffers::Offset<HotkeyPressed>(end);
    return o;
  }
};

inline flatbuffers::Offset<HotkeyPressed> CreateHotkeyPressed(
    flatbuffers::FlatBufferBuilder &_fbb) {
  HotkeyPressedBuilder builder_(_fbb);
  return builder_.Finish();
}

struct CaptureStart FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_FPS = 4,
    VT_SIZE_DIVIDER = 6,
    VT_GPU_COLOR_CONV = 8
  };
  uint32_t fps() const {
    return GetField<uint32_t>(VT_FPS, 0);
  }
  uint32_t size_divider() const {
    return GetField<uint32_t>(VT_SIZE_DIVIDER, 0);
  }
  bool gpu_color_conv() const {
    return GetField<uint8_t>(VT_GPU_COLOR_CONV, 0) != 0;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_FPS) &&
           VerifyField<uint32_t>(verifier, VT_SIZE_DIVIDER) &&
           VerifyField<uint8_t>(verifier, VT_GPU_COLOR_CONV) &&
           verifier.EndTable();
  }
};

struct CaptureStartBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_fps(uint32_t fps) {
    fbb_.AddElement<uint32_t>(CaptureStart::VT_FPS, fps, 0);
  }
  void add_size_divider(uint32_t size_divider) {
    fbb_.AddElement<uint32_t>(CaptureStart::VT_SIZE_DIVIDER, size_divider, 0);
  }
  void add_gpu_color_conv(bool gpu_color_conv) {
    fbb_.AddElement<uint8_t>(CaptureStart::VT_GPU_COLOR_CONV, static_cast<uint8_t>(gpu_color_conv), 0);
  }
  CaptureStartBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CaptureStartBuilder &operator=(const CaptureStartBuilder &);
  flatbuffers::Offset<CaptureStart> Finish() {
    const auto end = fbb_.EndTable(start_, 3);
    auto o = flatbuffers::Offset<CaptureStart>(end);
    return o;
  }
};

inline flatbuffers::Offset<CaptureStart> CreateCaptureStart(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t fps = 0,
    uint32_t size_divider = 0,
    bool gpu_color_conv = false) {
  CaptureStartBuilder builder_(_fbb);
  builder_.add_size_divider(size_divider);
  builder_.add_fps(fps);
  builder_.add_gpu_color_conv(gpu_color_conv);
  return builder_.Finish();
}

struct CaptureStop FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           verifier.EndTable();
  }
};

struct CaptureStopBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  CaptureStopBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CaptureStopBuilder &operator=(const CaptureStopBuilder &);
  flatbuffers::Offset<CaptureStop> Finish() {
    const auto end = fbb_.EndTable(start_, 0);
    auto o = flatbuffers::Offset<CaptureStop>(end);
    return o;
  }
};

inline flatbuffers::Offset<CaptureStop> CreateCaptureStop(
    flatbuffers::FlatBufferBuilder &_fbb) {
  CaptureStopBuilder builder_(_fbb);
  return builder_.Finish();
}

struct VideoSetup FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_WIDTH = 4,
    VT_HEIGHT = 6,
    VT_PIX_FMT = 8,
    VT_VFLIP = 10,
    VT_OFFSET = 12,
    VT_LINESIZE = 14,
    VT_SHMEM = 16,
    VT_AUDIO = 18
  };
  uint32_t width() const {
    return GetField<uint32_t>(VT_WIDTH, 0);
  }
  uint32_t height() const {
    return GetField<uint32_t>(VT_HEIGHT, 0);
  }
  PixFmt pix_fmt() const {
    return static_cast<PixFmt>(GetField<int32_t>(VT_PIX_FMT, 0));
  }
  bool vflip() const {
    return GetField<uint8_t>(VT_VFLIP, 0) != 0;
  }
  const flatbuffers::Vector<int64_t> *offset() const {
    return GetPointer<const flatbuffers::Vector<int64_t> *>(VT_OFFSET);
  }
  const flatbuffers::Vector<int64_t> *linesize() const {
    return GetPointer<const flatbuffers::Vector<int64_t> *>(VT_LINESIZE);
  }
  const Shmem *shmem() const {
    return GetPointer<const Shmem *>(VT_SHMEM);
  }
  const AudioSetup *audio() const {
    return GetPointer<const AudioSetup *>(VT_AUDIO);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_WIDTH) &&
           VerifyField<uint32_t>(verifier, VT_HEIGHT) &&
           VerifyField<int32_t>(verifier, VT_PIX_FMT) &&
           VerifyField<uint8_t>(verifier, VT_VFLIP) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_OFFSET) &&
           verifier.Verify(offset()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_LINESIZE) &&
           verifier.Verify(linesize()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SHMEM) &&
           verifier.VerifyTable(shmem()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_AUDIO) &&
           verifier.VerifyTable(audio()) &&
           verifier.EndTable();
  }
};

struct VideoSetupBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_width(uint32_t width) {
    fbb_.AddElement<uint32_t>(VideoSetup::VT_WIDTH, width, 0);
  }
  void add_height(uint32_t height) {
    fbb_.AddElement<uint32_t>(VideoSetup::VT_HEIGHT, height, 0);
  }
  void add_pix_fmt(PixFmt pix_fmt) {
    fbb_.AddElement<int32_t>(VideoSetup::VT_PIX_FMT, static_cast<int32_t>(pix_fmt), 0);
  }
  void add_vflip(bool vflip) {
    fbb_.AddElement<uint8_t>(VideoSetup::VT_VFLIP, static_cast<uint8_t>(vflip), 0);
  }
  void add_offset(flatbuffers::Offset<flatbuffers::Vector<int64_t>> offset) {
    fbb_.AddOffset(VideoSetup::VT_OFFSET, offset);
  }
  void add_linesize(flatbuffers::Offset<flatbuffers::Vector<int64_t>> linesize) {
    fbb_.AddOffset(VideoSetup::VT_LINESIZE, linesize);
  }
  void add_shmem(flatbuffers::Offset<Shmem> shmem) {
    fbb_.AddOffset(VideoSetup::VT_SHMEM, shmem);
  }
  void add_audio(flatbuffers::Offset<AudioSetup> audio) {
    fbb_.AddOffset(VideoSetup::VT_AUDIO, audio);
  }
  VideoSetupBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  VideoSetupBuilder &operator=(const VideoSetupBuilder &);
  flatbuffers::Offset<VideoSetup> Finish() {
    const auto end = fbb_.EndTable(start_, 8);
    auto o = flatbuffers::Offset<VideoSetup>(end);
    return o;
  }
};

inline flatbuffers::Offset<VideoSetup> CreateVideoSetup(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t width = 0,
    uint32_t height = 0,
    PixFmt pix_fmt = PixFmt_UNKNOWN,
    bool vflip = false,
    flatbuffers::Offset<flatbuffers::Vector<int64_t>> offset = 0,
    flatbuffers::Offset<flatbuffers::Vector<int64_t>> linesize = 0,
    flatbuffers::Offset<Shmem> shmem = 0,
    flatbuffers::Offset<AudioSetup> audio = 0) {
  VideoSetupBuilder builder_(_fbb);
  builder_.add_audio(audio);
  builder_.add_shmem(shmem);
  builder_.add_linesize(linesize);
  builder_.add_offset(offset);
  builder_.add_pix_fmt(pix_fmt);
  builder_.add_height(height);
  builder_.add_width(width);
  builder_.add_vflip(vflip);
  return builder_.Finish();
}

inline flatbuffers::Offset<VideoSetup> CreateVideoSetupDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t width = 0,
    uint32_t height = 0,
    PixFmt pix_fmt = PixFmt_UNKNOWN,
    bool vflip = false,
    const std::vector<int64_t> *offset = nullptr,
    const std::vector<int64_t> *linesize = nullptr,
    flatbuffers::Offset<Shmem> shmem = 0,
    flatbuffers::Offset<AudioSetup> audio = 0) {
  return capsule::messages::CreateVideoSetup(
      _fbb,
      width,
      height,
      pix_fmt,
      vflip,
      offset ? _fbb.CreateVector<int64_t>(*offset) : 0,
      linesize ? _fbb.CreateVector<int64_t>(*linesize) : 0,
      shmem,
      audio);
}

struct AudioSetup FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_CHANNELS = 4,
    VT_FORMAT = 6,
    VT_RATE = 8,
    VT_SHMEM = 10
  };
  uint32_t channels() const {
    return GetField<uint32_t>(VT_CHANNELS, 0);
  }
  SampleFmt format() const {
    return static_cast<SampleFmt>(GetField<int32_t>(VT_FORMAT, 0));
  }
  uint32_t rate() const {
    return GetField<uint32_t>(VT_RATE, 0);
  }
  const Shmem *shmem() const {
    return GetPointer<const Shmem *>(VT_SHMEM);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_CHANNELS) &&
           VerifyField<int32_t>(verifier, VT_FORMAT) &&
           VerifyField<uint32_t>(verifier, VT_RATE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SHMEM) &&
           verifier.VerifyTable(shmem()) &&
           verifier.EndTable();
  }
};

struct AudioSetupBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_channels(uint32_t channels) {
    fbb_.AddElement<uint32_t>(AudioSetup::VT_CHANNELS, channels, 0);
  }
  void add_format(SampleFmt format) {
    fbb_.AddElement<int32_t>(AudioSetup::VT_FORMAT, static_cast<int32_t>(format), 0);
  }
  void add_rate(uint32_t rate) {
    fbb_.AddElement<uint32_t>(AudioSetup::VT_RATE, rate, 0);
  }
  void add_shmem(flatbuffers::Offset<Shmem> shmem) {
    fbb_.AddOffset(AudioSetup::VT_SHMEM, shmem);
  }
  AudioSetupBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AudioSetupBuilder &operator=(const AudioSetupBuilder &);
  flatbuffers::Offset<AudioSetup> Finish() {
    const auto end = fbb_.EndTable(start_, 4);
    auto o = flatbuffers::Offset<AudioSetup>(end);
    return o;
  }
};

inline flatbuffers::Offset<AudioSetup> CreateAudioSetup(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t channels = 0,
    SampleFmt format = SampleFmt_UNKNOWN,
    uint32_t rate = 0,
    flatbuffers::Offset<Shmem> shmem = 0) {
  AudioSetupBuilder builder_(_fbb);
  builder_.add_shmem(shmem);
  builder_.add_rate(rate);
  builder_.add_format(format);
  builder_.add_channels(channels);
  return builder_.Finish();
}

struct Shmem FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_PATH = 4,
    VT_SIZE = 6
  };
  const flatbuffers::String *path() const {
    return GetPointer<const flatbuffers::String *>(VT_PATH);
  }
  uint64_t size() const {
    return GetField<uint64_t>(VT_SIZE, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PATH) &&
           verifier.Verify(path()) &&
           VerifyField<uint64_t>(verifier, VT_SIZE) &&
           verifier.EndTable();
  }
};

struct ShmemBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_path(flatbuffers::Offset<flatbuffers::String> path) {
    fbb_.AddOffset(Shmem::VT_PATH, path);
  }
  void add_size(uint64_t size) {
    fbb_.AddElement<uint64_t>(Shmem::VT_SIZE, size, 0);
  }
  ShmemBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ShmemBuilder &operator=(const ShmemBuilder &);
  flatbuffers::Offset<Shmem> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<Shmem>(end);
    return o;
  }
};

inline flatbuffers::Offset<Shmem> CreateShmem(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> path = 0,
    uint64_t size = 0) {
  ShmemBuilder builder_(_fbb);
  builder_.add_size(size);
  builder_.add_path(path);
  return builder_.Finish();
}

inline flatbuffers::Offset<Shmem> CreateShmemDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *path = nullptr,
    uint64_t size = 0) {
  return capsule::messages::CreateShmem(
      _fbb,
      path ? _fbb.CreateString(path) : 0,
      size);
}

struct AudioFramesCommitted FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_OFFSET = 4,
    VT_FRAMES = 6
  };
  uint32_t offset() const {
    return GetField<uint32_t>(VT_OFFSET, 0);
  }
  uint32_t frames() const {
    return GetField<uint32_t>(VT_FRAMES, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_OFFSET) &&
           VerifyField<uint32_t>(verifier, VT_FRAMES) &&
           verifier.EndTable();
  }
};

struct AudioFramesCommittedBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_offset(uint32_t offset) {
    fbb_.AddElement<uint32_t>(AudioFramesCommitted::VT_OFFSET, offset, 0);
  }
  void add_frames(uint32_t frames) {
    fbb_.AddElement<uint32_t>(AudioFramesCommitted::VT_FRAMES, frames, 0);
  }
  AudioFramesCommittedBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AudioFramesCommittedBuilder &operator=(const AudioFramesCommittedBuilder &);
  flatbuffers::Offset<AudioFramesCommitted> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<AudioFramesCommitted>(end);
    return o;
  }
};

inline flatbuffers::Offset<AudioFramesCommitted> CreateAudioFramesCommitted(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t offset = 0,
    uint32_t frames = 0) {
  AudioFramesCommittedBuilder builder_(_fbb);
  builder_.add_frames(frames);
  builder_.add_offset(offset);
  return builder_.Finish();
}

struct AudioFramesProcessed FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_OFFSET = 4,
    VT_FRAMES = 6
  };
  uint32_t offset() const {
    return GetField<uint32_t>(VT_OFFSET, 0);
  }
  uint32_t frames() const {
    return GetField<uint32_t>(VT_FRAMES, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_OFFSET) &&
           VerifyField<uint32_t>(verifier, VT_FRAMES) &&
           verifier.EndTable();
  }
};

struct AudioFramesProcessedBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_offset(uint32_t offset) {
    fbb_.AddElement<uint32_t>(AudioFramesProcessed::VT_OFFSET, offset, 0);
  }
  void add_frames(uint32_t frames) {
    fbb_.AddElement<uint32_t>(AudioFramesProcessed::VT_FRAMES, frames, 0);
  }
  AudioFramesProcessedBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AudioFramesProcessedBuilder &operator=(const AudioFramesProcessedBuilder &);
  flatbuffers::Offset<AudioFramesProcessed> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<AudioFramesProcessed>(end);
    return o;
  }
};

inline flatbuffers::Offset<AudioFramesProcessed> CreateAudioFramesProcessed(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t offset = 0,
    uint32_t frames = 0) {
  AudioFramesProcessedBuilder builder_(_fbb);
  builder_.add_frames(frames);
  builder_.add_offset(offset);
  return builder_.Finish();
}

struct VideoFrameCommitted FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_TIMESTAMP = 4,
    VT_INDEX = 6
  };
  uint64_t timestamp() const {
    return GetField<uint64_t>(VT_TIMESTAMP, 0);
  }
  uint32_t index() const {
    return GetField<uint32_t>(VT_INDEX, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_TIMESTAMP) &&
           VerifyField<uint32_t>(verifier, VT_INDEX) &&
           verifier.EndTable();
  }
};

struct VideoFrameCommittedBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_timestamp(uint64_t timestamp) {
    fbb_.AddElement<uint64_t>(VideoFrameCommitted::VT_TIMESTAMP, timestamp, 0);
  }
  void add_index(uint32_t index) {
    fbb_.AddElement<uint32_t>(VideoFrameCommitted::VT_INDEX, index, 0);
  }
  VideoFrameCommittedBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  VideoFrameCommittedBuilder &operator=(const VideoFrameCommittedBuilder &);
  flatbuffers::Offset<VideoFrameCommitted> Finish() {
    const auto end = fbb_.EndTable(start_, 2);
    auto o = flatbuffers::Offset<VideoFrameCommitted>(end);
    return o;
  }
};

inline flatbuffers::Offset<VideoFrameCommitted> CreateVideoFrameCommitted(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t timestamp = 0,
    uint32_t index = 0) {
  VideoFrameCommittedBuilder builder_(_fbb);
  builder_.add_timestamp(timestamp);
  builder_.add_index(index);
  return builder_.Finish();
}

struct VideoFrameProcessed FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_INDEX = 4
  };
  uint32_t index() const {
    return GetField<uint32_t>(VT_INDEX, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_INDEX) &&
           verifier.EndTable();
  }
};

struct VideoFrameProcessedBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_index(uint32_t index) {
    fbb_.AddElement<uint32_t>(VideoFrameProcessed::VT_INDEX, index, 0);
  }
  VideoFrameProcessedBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  VideoFrameProcessedBuilder &operator=(const VideoFrameProcessedBuilder &);
  flatbuffers::Offset<VideoFrameProcessed> Finish() {
    const auto end = fbb_.EndTable(start_, 1);
    auto o = flatbuffers::Offset<VideoFrameProcessed>(end);
    return o;
  }
};

inline flatbuffers::Offset<VideoFrameProcessed> CreateVideoFrameProcessed(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t index = 0) {
  VideoFrameProcessedBuilder builder_(_fbb);
  builder_.add_index(index);
  return builder_.Finish();
}

inline bool VerifyMessage(flatbuffers::Verifier &verifier, const void *obj, Message type) {
  switch (type) {
    case Message_NONE: {
      return true;
    }
    case Message_ReadyForYou: {
      auto ptr = reinterpret_cast<const ReadyForYou *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_HotkeyPressed: {
      auto ptr = reinterpret_cast<const HotkeyPressed *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_CaptureStart: {
      auto ptr = reinterpret_cast<const CaptureStart *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_CaptureStop: {
      auto ptr = reinterpret_cast<const CaptureStop *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_VideoSetup: {
      auto ptr = reinterpret_cast<const VideoSetup *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_VideoFrameCommitted: {
      auto ptr = reinterpret_cast<const VideoFrameCommitted *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_VideoFrameProcessed: {
      auto ptr = reinterpret_cast<const VideoFrameProcessed *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_AudioFramesCommitted: {
      auto ptr = reinterpret_cast<const AudioFramesCommitted *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_AudioFramesProcessed: {
      auto ptr = reinterpret_cast<const AudioFramesProcessed *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_SawBackend: {
      auto ptr = reinterpret_cast<const SawBackend *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyMessage(
        verifier,  values->Get(i), types->GetEnum<Message>(i))) {
      return false;
    }
  }
  return true;
}

inline const capsule::messages::Packet *GetPacket(const void *buf) {
  return flatbuffers::GetRoot<capsule::messages::Packet>(buf);
}

inline bool VerifyPacketBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<capsule::messages::Packet>(nullptr);
}

inline void FinishPacketBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<capsule::messages::Packet> root) {
  fbb.Finish(root);
}

}  // namespace messages
}  // namespace capsule

#endif  // FLATBUFFERS_GENERATED_MESSAGES_CAPSULE_MESSAGES_H_
