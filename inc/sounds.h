#ifndef SOUNDS_H
# define SOUNDS_H

# define LEVEL_CLEARED_SYSTEM_CALL         "aplay assets/sounds/gong.wav > /dev/null 2>&1 &"

# define HEALTH_PICKUP_SYSTEM_CALL         "aplay assets/sounds/health.wav > /dev/null 2>&1 &"
# define EATING_SOUND_SYSTEM_CALL          "aplay assets/sounds/eat.wav > /dev/null 2>&1 &"
# define ALERT_SYSTEM_CALL                 "aplay assets/sounds/alert.wav > /dev/null 2>&1 &"
# define SLIDING_DOOR_SYSTEM_CALL          "aplay assets/sounds/sliding-door.wav > /dev/null 2>&1 &"

# define KNIFE_ATTACK_SOUND                "aplay assets/ui/knife/attack.wav > /dev/null 2>&1 &"
# define PISTOL_ATTACK_SOUND               "aplay assets/ui/pistol/attack.wav > /dev/null 2>&1 &"
# define RIFLE_ATTACK_SOUND                "aplay assets/ui/rifle/attack.wav > /dev/null 2>&1 &"
# define MACHINE_GUN_ATTACK_SOUND          "aplay assets/ui/machine-gun/attack.wav > /dev/null 2>&1 &"
# define EMPTY_GUN_SOUND                   "aplay assets/sounds/empty-gun.wav > /dev/null 2>&1 &"

# define BUBBLE_POP_SOUND                   "aplay assets/sounds/bubble-pop.wav > /dev/null 2>&1 &"

# define DEATH_SOUND                        "aplay assets/sounds/death.wav > /dev/null 2>&1 &"

#endif