## 采集音频

```shell
ffmpeg.exe -f dshow -i audio="麦克风 (Realtek(R) Audio)"  -ar 16000 -ac 1 save.wav
```

## 播放音频

```shell
ffplay.exe -ar 44100 -channels 2 -f s16le -i save.wav
```

