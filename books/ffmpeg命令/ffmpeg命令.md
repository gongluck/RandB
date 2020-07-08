## 采集音频

```shell
ffmpeg.exe -f dshow -i audio="麦克风 (Realtek(R) Audio)"  -ar 16000 -ac 1 save.wav
```

