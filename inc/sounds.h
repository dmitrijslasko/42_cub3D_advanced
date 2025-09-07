#ifndef SOUNDS_H
# define SOUNDS_H

# define HEALTH_PICKUP_SYSTEM_CALL         "aplay sounds/health.wav > /dev/null 2>&1 &"
# define EATING_SOUND_SYSTEM_CALL          "aplay sounds/eat.wav > /dev/null 2>&1 &"
# define LEVEL_CLEARED_SYSTEM_CALL         "aplay sounds/success.wav > /dev/null 2>&1 &"
# define ALERT_SYSTEM_CALL                 "aplay sounds/alert.wav > /dev/null 2>&1 &"
# define SLIDING_DOOR_SYSTEM_CALL          "aplay sounds/sliding-door.wav > /dev/null 2>&1 &"

# define KNIFE_ATTACK_SOUND                "aplay ui/knife/attack.wav > /dev/null 2>&1 &"
# define PISTOL_ATTACK_SOUND               "aplay sounds/shot.wav > /dev/null 2>&1 &"
# define RIFLE_ATTACK_SOUND                "aplay ui/rifle/attack.wav > /dev/null 2>&1 &"
# define MACHINE_GUN_ATTACK_SOUND          "aplay ui/machine-gun/attack.wav > /dev/null 2>&1 &"

#endif