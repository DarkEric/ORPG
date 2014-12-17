#ifndef STATS_H
#define STATS_H
// Stats.h

static const int ID_TYPE_BERSERK=21;
static const int ID_TYPE_TROLL=84;
static const int ID_TYPE_DRAGON=68;
//-------------------------------------------------------------------------------------

static const int WARRIOR_START_HP = 100;
static const int WARRIOR_ENERGY_MAX=100;
static const int HERO_START_POS_X = 7;
static const int HERO_START_POS_Y = 16;
static const int WARRIOR_START_STR = 10;
//-------------------------------------------------------------------------------------

static const int WARRIOR_EXP_TO_2 = 100;
static const int WARRIOR_EXP_TO_3 = 300;
static const int WARRIOR_EXP_TO_4 = 800;
static const int WARRIOR_EXP_TO_5 = 1000;

//-------------------------------------------------------------------------------------

static const int WARRIOR_HITS_1 = 15;
static const int WARRIOR_ATTACK_1 = 2;
static const int WARRIOR_DEFENSE_1 = 1;

static const int WARRIOR_HITS_2 = 16;
static const int WARRIOR_ATTACK_2 = 3;
static const int WARRIOR_DEFENSE_2 = 2;

static const int WARRIOR_HITS_3 = 17;
static const int WARRIOR_ATTACK_3 = 4;
static const int WARRIOR_DEFENSE_3 = 3;

static const int WARRIOR_HITS_4 = 18;
static const int WARRIOR_ATTACK_4 = 5;
static const int WARRIOR_DEFENSE_4 = 4;

//-------------------------------------------------------------------------------------

static const int IMP_HITS = 5;
static const int IMP_ATTACK = 1;
static const int IMP_DEFENSE = 1;
static const int IMP_SIGHT_RADIUS = 5;
static const int IMP_EXPERIENCE = 40;

static const int SKELETON_HITS = 4;
static const int SKELETON_ATTACK = 2;
static const int SKELETON_DEFENSE = 1;
static const int SKELETON_SIGHT_RADIUS = 3;
static const int SKELETON_EXPERIENCE = 60;

static const int TROLL_PATTACK = 15;
static const int TROLL_PDEFENSE = 10;
static const int TROLL_MDEFENSE = 2;
static const int TROLL_SIGHT_RADIUS = 3;
static const int TROLL_EXPERIENCE = 50;
static const int TROLL_START_HP = 200;
static const int TROLL_START_ENERGY = 50;
static const int TROLL_LEVEL=5;

static const int DRAGON_PATTACK = 25;
static const int DRAGON_PDEFENSE = 12;
static const int DRAGON_MDEFENSE = 16;
static const int DRAGON_SIGHT_RADIUS = 3;
static const int DRAGON_EXPERIENCE = 100;
static const int DRAGON_START_HP = 215;
static const int DRAGON_START_ENERGY = 85;
static const int DRAGON_LEVEL=10;

static const int WIZARD_HITS = 10;
static const int WIZARD_ATTACK = 4;
static const int WIZARD_DEFENSE = 3;
static const int WIZARD_SIGHT_RADIUS = 5;
static const int WIZARD_EXPERIENCE = 500;

//-------------------------------------------------------------------------------------

static const int SWORD_ATTACK = 1;
static const int SWORD_DEFENSE = 0;

static const int SHIELD_ATTACK = 0;
static const int SHIELD_DEFENSE = 1;

static const int CUIRASS_ATTACK = 0;
static const int CUIRASS_DEFENSE = 3;

//-------------------------------------------------------------------------------------

static const int MOB_START_HP = 100;
static const int MOB_PATTACK = 3;
static const int MOB_MATTACK = 3;
static const int MOB_PDEFENSE = 3;
static const int MOB_MDEFENSE = 3;

//-------------------------------------------------------------------------------------
#endif // STATS_H
