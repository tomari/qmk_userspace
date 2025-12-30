OS_DETECTION_ENABLE = yes
BACKLIGHT_ENABLE = yes
ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
