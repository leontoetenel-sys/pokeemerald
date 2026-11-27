// Custom encounter tables: weights are percentages and must sum to 100.
// Only listed map/method combinations override vanilla encounters.
struct WeightedWildPokemon { struct WildPokemon mon; u8 weight; };
struct WeightedWildTable { u16 headerId; u8 area; u8 count; const struct WeightedWildPokemon *mons; };
static const struct WeightedWildPokemon sWeighted_ROUTE101_land_mons[] = {
    {{2, 3, SPECIES_WURMPLE}, 45},
    {{2, 3, SPECIES_POOCHYENA}, 33},
    {{2, 3, SPECIES_ZIGZAGOON}, 10},
    {{2, 3, SPECIES_RATTATA}, 4},
    {{2, 3, SPECIES_SENTRET}, 4},
    {{2, 3, SPECIES_PIDGEY}, 4},
};
static const struct WeightedWildPokemon sWeighted_ROUTE102_land_mons[] = {
    {{3, 4, SPECIES_POOCHYENA}, 22},
    {{3, 4, SPECIES_WURMPLE}, 30},
    {{3, 4, SPECIES_LOTAD}, 20},
    {{3, 4, SPECIES_ZIGZAGOON}, 7},
    {{4, 4, SPECIES_RALTS}, 4},
    {{3, 3, SPECIES_SEEDOT}, 1},
    {{3, 4, SPECIES_PIDGEY}, 4},
    {{3, 4, SPECIES_SPEAROW}, 4},
    {{3, 4, SPECIES_NIDORAN_F}, 4},
    {{3, 4, SPECIES_NIDORAN_M}, 4},
};
static const struct WeightedWildPokemon sWeighted_ROUTE103_land_mons[] = {
    {{2, 4, SPECIES_POOCHYENA}, 44},
    {{2, 4, SPECIES_WINGULL}, 20},
    {{3, 4, SPECIES_ZIGZAGOON}, 20},
    {{2, 4, SPECIES_PIDGEY}, 4},
    {{2, 4, SPECIES_SPEAROW}, 4},
    {{2, 4, SPECIES_NIDORAN_F}, 4},
    {{2, 4, SPECIES_NIDORAN_M}, 4},
};
static const struct WeightedWildPokemon sWeighted_ROUTE104_land_mons[] = {
    {{4, 5, SPECIES_POOCHYENA}, 24},
    {{4, 4, SPECIES_WURMPLE}, 20},
    {{4, 5, SPECIES_MARILL}, 10},
    {{4, 5, SPECIES_TAILLOW}, 5},
    {{3, 5, SPECIES_WINGULL}, 10},
    {{4, 5, SPECIES_PIDGEY}, 9},
    {{4, 5, SPECIES_SPEAROW}, 4},
    {{4, 5, SPECIES_NIDORAN_F}, 4},
    {{4, 5, SPECIES_NIDORAN_M}, 4},
    {{4, 5, SPECIES_WOOPER}, 10},
};
static const struct WeightedWildPokemon sWeighted_ROUTE110_land_mons[] = {
    {{12, 12, SPECIES_POOCHYENA}, 17},
    {{12, 13, SPECIES_ELECTRIKE}, 29},
    {{12, 13, SPECIES_GULPIN}, 15},
    {{13, 13, SPECIES_MINUN}, 15},
    {{13, 13, SPECIES_ODDISH}, 10},
    {{12, 12, SPECIES_SPEAROW}, 8},
    {{12, 13, SPECIES_PLUSLE}, 2},
    {{6, 15, SPECIES_EEVEE}, 2},
    {{6, 15, SPECIES_PICHU}, 2},
};
static const struct WeightedWildPokemon sWeighted_ROUTE111_land_mons[] = {
    {{19, 21, SPECIES_SANDSHREW}, 29},
    {{19, 21, SPECIES_TRAPINCH}, 34},
    {{19, 21, SPECIES_BALTOY}, 24},
    {{20, 22, SPECIES_CACNEA}, 6},
    {{6, 15, SPECIES_EEVEE}, 2},
    {{6, 15, SPECIES_PICHU}, 2},
    {{19, 21, SPECIES_LARVITAR}, 3},
};
static const struct WeightedWildPokemon sWeighted_ROUTE110_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 50},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
    {{15, 15, SPECIES_SQUIRTLE}, 5},
    {{15, 15, SPECIES_MUDKIP}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE117_water_mons[] = {
    {{5, 35, SPECIES_MARILL}, 89},
    {{20, 30, SPECIES_GOLDEEN}, 1},
    {{15, 15, SPECIES_SQUIRTLE}, 5},
    {{15, 15, SPECIES_MUDKIP}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE118_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 50},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
    {{15, 15, SPECIES_SQUIRTLE}, 5},
    {{15, 15, SPECIES_MUDKIP}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE111_rock_smash_mons[] = {
    {{5, 20, SPECIES_ONIX}, 70},
    {{10, 20, SPECIES_NOSEPASS}, 30},
};
static const struct WeightedWildPokemon sWeighted_ROUTE114_rock_smash_mons[] = {
    {{5, 20, SPECIES_ONIX}, 70},
    {{10, 20, SPECIES_NOSEPASS}, 30},
};
static const struct WeightedWildPokemon sWeighted_ROUTE112_land_mons[] = {
    {{14, 16, SPECIES_NUMEL}, 75},
    {{14, 16, SPECIES_WOOPER}, 25},
};
static const struct WeightedWildPokemon sWeighted_ROUTE116_land_mons[] = {
    {{6, 8, SPECIES_SNUBBULL}, 28},
    {{6, 6, SPECIES_WHISMUR}, 20},
    {{6, 7, SPECIES_NINCADA}, 20},
    {{7, 7, SPECIES_ABRA}, 10},
    {{6, 8, SPECIES_TAILLOW}, 20},
    {{7, 8, SPECIES_SKITTY}, 2},
};
static const struct WeightedWildPokemon sWeighted_ROUTE117_land_mons[] = {
    {{13, 14, SPECIES_POOCHYENA}, 15},
    {{15, 15, SPECIES_SPEAROW}, 10},
    {{13, 14, SPECIES_ODDISH}, 40},
    {{13, 13, SPECIES_WOOPER}, 10},
    {{13, 14, SPECIES_ILLUMISE}, 18},
    {{13, 13, SPECIES_VOLBEAT}, 1},
    {{13, 13, SPECIES_SEEDOT}, 1},
    {{13, 14, SPECIES_HOUNDOUR}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE118_land_mons[] = {
    {{24, 26, SPECIES_ZIGZAGOON}, 28},
    {{24, 26, SPECIES_ELECTRIKE}, 28},
    {{26, 26, SPECIES_LINOONE}, 10},
    {{26, 26, SPECIES_MANECTRIC}, 10},
    {{25, 27, SPECIES_HOUNDOUR}, 19},
    {{25, 25, SPECIES_KECLEON}, 1},
    {{11, 18, SPECIES_EEVEE}, 2},
    {{5, 18, SPECIES_PICHU}, 2},
};
static const struct WeightedWildPokemon sWeighted_PETALBURG_WOODS_land_mons[] = {
    {{5, 6, SPECIES_POOCHYENA}, 25},
    {{5, 6, SPECIES_WURMPLE}, 23},
    {{5, 6, SPECIES_SHROOMISH}, 15},
    {{5, 5, SPECIES_SILCOON}, 10},
    {{5, 5, SPECIES_CASCOON}, 10},
    {{5, 6, SPECIES_TAILLOW}, 5},
    {{5, 6, SPECIES_SLAKOTH}, 5},
    {{5, 6, SPECIES_CHIKORITA}, 5},
    {{5, 6, SPECIES_BULBASAUR}, 2},
};
static const struct WeightedWildPokemon sWeighted_RUSTURF_TUNNEL_land_mons[] = {
    {{5, 8, SPECIES_WHISMUR}, 85},
    {{5, 8, SPECIES_RATTATA}, 10},
    {{5, 8, SPECIES_DUNSPARCE}, 5},
};
static const struct WeightedWildPokemon sWeighted_GRANITE_CAVE_1F_land_mons[] = {
    {{7, 8, SPECIES_ZUBAT}, 30},
    {{6, 10, SPECIES_MAKUHITA}, 50},
    {{8, 8, SPECIES_ABRA}, 4},
    {{6, 9, SPECIES_GEODUDE}, 10},
    {{8, 8, SPECIES_ONIX}, 4},
    {{8, 8, SPECIES_LARVITAR}, 2},
};
static const struct WeightedWildPokemon sWeighted_GRANITE_CAVE_B1F_land_mons[] = {
    {{9, 10, SPECIES_ZUBAT}, 30},
    {{9, 11, SPECIES_ARON}, 40},
    {{9, 9, SPECIES_ABRA}, 4},
    {{10, 11, SPECIES_MAKUHITA}, 10},
    {{9, 11, SPECIES_SABLEYE}, 10},
    {{9, 9, SPECIES_ONIX}, 4},
    {{9, 9, SPECIES_LARVITAR}, 2},
};
static const struct WeightedWildPokemon sWeighted_GRANITE_CAVE_B2F_land_mons[] = {
    {{10, 11, SPECIES_ZUBAT}, 30},
    {{10, 12, SPECIES_ARON}, 40},
    {{10, 10, SPECIES_ABRA}, 5},
    {{10, 12, SPECIES_SABLEYE}, 20},
    {{10, 10, SPECIES_DUNSPARCE}, 5},
};
static const struct WeightedWildPokemon sWeighted_FIERY_PATH_land_mons[] = {
    {{15, 16, SPECIES_NUMEL}, 25},
    {{15, 16, SPECIES_KOFFING}, 25},
    {{15, 16, SPECIES_MACHOP}, 15},
    {{14, 16, SPECIES_TORKOAL}, 18},
    {{15, 15, SPECIES_SLUGMA}, 10},
    {{14, 14, SPECIES_GRIMER}, 2},
    {{15, 15, SPECIES_GROWLITHE}, 1},
    {{5, 15, SPECIES_CHARMANDER}, 2},
    {{15, 15, SPECIES_HOUNDOUR}, 1},
    {{15, 15, SPECIES_TORCHIC}, 1},
};
static const struct WeightedWildPokemon sWeighted_ROUTE106_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 50},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 4},
    {{5, 35, SPECIES_KRABBY}, 5},
    {{5, 35, SPECIES_SEEL}, 5},
    {{25, 30, SPECIES_DRATINI}, 1},
};
static const struct WeightedWildPokemon sWeighted_ROUTE107_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 50},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
    {{5, 35, SPECIES_KRABBY}, 5},
    {{5, 35, SPECIES_SEEL}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE108_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 50},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 4},
    {{5, 35, SPECIES_KRABBY}, 5},
    {{5, 35, SPECIES_SEEL}, 5},
    {{25, 30, SPECIES_DRATINI}, 1},
};
static const struct WeightedWildPokemon sWeighted_ROUTE109_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 50},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 4},
    {{5, 35, SPECIES_KRABBY}, 5},
    {{5, 35, SPECIES_SEEL}, 5},
    {{25, 30, SPECIES_DRATINI}, 1},
};
static const struct WeightedWildPokemon sWeighted_MT_PYRE_2F_land_mons[] = {
    {{22, 29, SPECIES_SHUPPET}, 85},
    {{19, 24, SPECIES_GASTLY}, 3},
    {{25, 30, SPECIES_HAUNTER}, 2},
    {{22, 29, SPECIES_SABLEYE}, 10},
};
static const struct WeightedWildPokemon sWeighted_MT_PYRE_3F_land_mons[] = {
    {{22, 29, SPECIES_SHUPPET}, 85},
    {{19, 24, SPECIES_GASTLY}, 3},
    {{25, 30, SPECIES_HAUNTER}, 2},
    {{22, 29, SPECIES_SABLEYE}, 10},
};
static const struct WeightedWildPokemon sWeighted_MT_PYRE_4F_land_mons[] = {
    {{22, 29, SPECIES_SHUPPET}, 85},
    {{25, 29, SPECIES_DUSKULL}, 10},
    {{19, 24, SPECIES_GASTLY}, 3},
    {{25, 30, SPECIES_HAUNTER}, 2},
};
static const struct WeightedWildPokemon sWeighted_MT_PYRE_5F_land_mons[] = {
    {{22, 29, SPECIES_SHUPPET}, 85},
    {{25, 29, SPECIES_DUSKULL}, 10},
    {{19, 24, SPECIES_GASTLY}, 3},
    {{25, 30, SPECIES_HAUNTER}, 2},
};
static const struct WeightedWildPokemon sWeighted_MT_PYRE_6F_land_mons[] = {
    {{22, 29, SPECIES_SHUPPET}, 85},
    {{25, 29, SPECIES_DUSKULL}, 10},
    {{19, 24, SPECIES_GASTLY}, 3},
    {{25, 30, SPECIES_HAUNTER}, 2},
};
static const struct WeightedWildPokemon sWeighted_MT_PYRE_EXTERIOR_land_mons[] = {
    {{27, 29, SPECIES_SHUPPET}, 48},
    {{25, 29, SPECIES_VULPIX}, 30},
    {{12, 15, SPECIES_TORCHIC}, 10},
    {{12, 15, SPECIES_CHARMANDER}, 2},
    {{27, 31, SPECIES_SABLEYE}, 10},
};
static const struct WeightedWildPokemon sWeighted_ROUTE103_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE104_water_mons[] = {
    {{10, 30, SPECIES_MANTINE}, 95},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE105_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE113_land_mons[] = {
    {{15, 15, SPECIES_SPINDA}, 35},
    {{14, 14, SPECIES_SPINDA}, 20},
    {{16, 16, SPECIES_SPINDA}, 10},
    {{15, 15, SPECIES_SLUGMA}, 10},
    {{14, 14, SPECIES_SLUGMA}, 10},
    {{16, 16, SPECIES_SLUGMA}, 5},
    {{16, 16, SPECIES_SKARMORY}, 5},
    {{14, 16, SPECIES_GROWLITHE}, 3},
    {{14, 16, SPECIES_PONYTA}, 2},
};
static const struct WeightedWildPokemon sWeighted_ROUTE114_water_mons[] = {
    {{20, 30, SPECIES_MARILL}, 60},
    {{10, 20, SPECIES_MARILL}, 30},
    {{30, 35, SPECIES_MARILL}, 5},
    {{5, 10, SPECIES_MARILL}, 3},
    {{20, 30, SPECIES_GOLDEEN}, 1},
    {{20, 25, SPECIES_LAPRAS}, 1},
};
static const struct WeightedWildPokemon sWeighted_ROUTE115_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 54},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
    {{15, 20, SPECIES_DRATINI}, 3},
    {{20, 25, SPECIES_LAPRAS}, 3},
};
static const struct WeightedWildPokemon sWeighted_ROUTE119_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE121_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE122_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE123_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE124_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE125_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE126_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_LAPRAS}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE127_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE128_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE129_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_LAPRAS}, 4},
    {{25, 30, SPECIES_WAILORD}, 1},
};
static const struct WeightedWildPokemon sWeighted_ROUTE130_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE131_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_LAPRAS}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE132_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE133_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_ROUTE134_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_LILYCOVE_CITY_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_LAPRAS}, 5},
};
static const struct WeightedWildPokemon sWeighted_DEWFORD_TOWN_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_SLATEPORT_CITY_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_MOSSDEEP_CITY_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_LAPRAS}, 5},
};
static const struct WeightedWildPokemon sWeighted_PACIFIDLOG_TOWN_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_EVER_GRANDE_CITY_water_mons[] = {
    {{5, 35, SPECIES_TENTACOOL}, 60},
    {{10, 30, SPECIES_MANTINE}, 35},
    {{25, 30, SPECIES_PELIPPER}, 5},
};
static const struct WeightedWildPokemon sWeighted_NEW_MAUVILLE_INSIDE_land_mons[] = {
    {{22, 26, SPECIES_VOLTORB}, 46},
    {{22, 26, SPECIES_MAGNEMITE}, 46},
    {{26, 26, SPECIES_ELECTRODE}, 1},
    {{26, 26, SPECIES_MAGNETON}, 1},
    {{24, 27, SPECIES_PIKACHU}, 2},
    {{24, 27, SPECIES_MUK}, 4},
};
static const struct WeightedWildPokemon sWeighted_ROUTE119_land_mons[] = {
    {{25, 27, SPECIES_ZIGZAGOON}, 25},
    {{25, 27, SPECIES_LINOONE}, 25},
    {{24, 27, SPECIES_ODDISH}, 30},
    {{25, 27, SPECIES_TROPIUS}, 9},
    {{25, 25, SPECIES_KECLEON}, 1},
    {{23, 29, SPECIES_SCYTHER}, 5},
    {{23, 29, SPECIES_PINSIR}, 5},
};
static const struct WeightedWildPokemon sWeighted_MT_PYRE_SUMMIT_land_mons[] = {
    {{28, 28, SPECIES_SHUPPET}, 10},
    {{29, 29, SPECIES_SHUPPET}, 20},
    {{27, 27, SPECIES_SHUPPET}, 10},
    {{26, 26, SPECIES_SHUPPET}, 10},
    {{30, 30, SPECIES_SHUPPET}, 10},
    {{25, 25, SPECIES_SHUPPET}, 10},
    {{24, 24, SPECIES_SHUPPET}, 5},
    {{28, 28, SPECIES_DUSKULL}, 5},
    {{26, 26, SPECIES_DUSKULL}, 4},
    {{30, 30, SPECIES_DUSKULL}, 4},
    {{28, 28, SPECIES_CHIMECHO}, 2},
    {{28, 35, SPECIES_SABLEYE}, 10},
};
static const struct WeightedWildTable sWeightedWildTables[] = {
    {44, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_MT_PYRE_SUMMIT_land_mons), sWeighted_MT_PYRE_SUMMIT_land_mons},
    {8, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE113_land_mons), sWeighted_ROUTE113_land_mons},
    {9, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE114_water_mons), sWeighted_ROUTE114_water_mons},
    {32, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_NEW_MAUVILLE_INSIDE_land_mons), sWeighted_NEW_MAUVILLE_INSIDE_land_mons},
    {33, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE119_land_mons), sWeighted_ROUTE119_land_mons},
    {0, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE101_land_mons), sWeighted_ROUTE101_land_mons},
    {1, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE102_land_mons), sWeighted_ROUTE102_land_mons},
    {2, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE103_land_mons), sWeighted_ROUTE103_land_mons},
    {3, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE104_land_mons), sWeighted_ROUTE104_land_mons},
    {5, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE110_land_mons), sWeighted_ROUTE110_land_mons},
    {6, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE111_land_mons), sWeighted_ROUTE111_land_mons},
    {5, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE110_water_mons), sWeighted_ROUTE110_water_mons},
    {11, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE117_water_mons), sWeighted_ROUTE117_water_mons},
    {12, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE118_water_mons), sWeighted_ROUTE118_water_mons},
    {6, WILD_AREA_ROCKS, ARRAY_COUNT(sWeighted_ROUTE111_rock_smash_mons), sWeighted_ROUTE111_rock_smash_mons},
    {9, WILD_AREA_ROCKS, ARRAY_COUNT(sWeighted_ROUTE114_rock_smash_mons), sWeighted_ROUTE114_rock_smash_mons},
    {7, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE112_land_mons), sWeighted_ROUTE112_land_mons},
    {10, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE116_land_mons), sWeighted_ROUTE116_land_mons},
    {11, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE117_land_mons), sWeighted_ROUTE117_land_mons},
    {12, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_ROUTE118_land_mons), sWeighted_ROUTE118_land_mons},
    {14, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_PETALBURG_WOODS_land_mons), sWeighted_PETALBURG_WOODS_land_mons},
    {15, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_RUSTURF_TUNNEL_land_mons), sWeighted_RUSTURF_TUNNEL_land_mons},
    {16, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_GRANITE_CAVE_1F_land_mons), sWeighted_GRANITE_CAVE_1F_land_mons},
    {17, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_GRANITE_CAVE_B1F_land_mons), sWeighted_GRANITE_CAVE_B1F_land_mons},
    {23, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_GRANITE_CAVE_B2F_land_mons), sWeighted_GRANITE_CAVE_B2F_land_mons},
    {24, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_FIERY_PATH_land_mons), sWeighted_FIERY_PATH_land_mons},
    {27, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE106_water_mons), sWeighted_ROUTE106_water_mons},
    {28, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE107_water_mons), sWeighted_ROUTE107_water_mons},
    {29, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE108_water_mons), sWeighted_ROUTE108_water_mons},
    {30, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE109_water_mons), sWeighted_ROUTE109_water_mons},
    {38, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_MT_PYRE_2F_land_mons), sWeighted_MT_PYRE_2F_land_mons},
    {39, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_MT_PYRE_3F_land_mons), sWeighted_MT_PYRE_3F_land_mons},
    {40, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_MT_PYRE_4F_land_mons), sWeighted_MT_PYRE_4F_land_mons},
    {41, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_MT_PYRE_5F_land_mons), sWeighted_MT_PYRE_5F_land_mons},
    {42, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_MT_PYRE_6F_land_mons), sWeighted_MT_PYRE_6F_land_mons},
    {43, WILD_AREA_LAND, ARRAY_COUNT(sWeighted_MT_PYRE_EXTERIOR_land_mons), sWeighted_MT_PYRE_EXTERIOR_land_mons},
    {2, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE103_water_mons), sWeighted_ROUTE103_water_mons},
    {3, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE104_water_mons), sWeighted_ROUTE104_water_mons},
    {4, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE105_water_mons), sWeighted_ROUTE105_water_mons},
    {31, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE115_water_mons), sWeighted_ROUTE115_water_mons},
    {33, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE119_water_mons), sWeighted_ROUTE119_water_mons},
    {35, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE121_water_mons), sWeighted_ROUTE121_water_mons},
    {36, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE122_water_mons), sWeighted_ROUTE122_water_mons},
    {37, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE123_water_mons), sWeighted_ROUTE123_water_mons},
    {13, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE124_water_mons), sWeighted_ROUTE124_water_mons},
    {46, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE125_water_mons), sWeighted_ROUTE125_water_mons},
    {47, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE126_water_mons), sWeighted_ROUTE126_water_mons},
    {48, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE127_water_mons), sWeighted_ROUTE127_water_mons},
    {49, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE128_water_mons), sWeighted_ROUTE128_water_mons},
    {50, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE129_water_mons), sWeighted_ROUTE129_water_mons},
    {51, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE130_water_mons), sWeighted_ROUTE130_water_mons},
    {52, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE131_water_mons), sWeighted_ROUTE131_water_mons},
    {53, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE132_water_mons), sWeighted_ROUTE132_water_mons},
    {54, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE133_water_mons), sWeighted_ROUTE133_water_mons},
    {55, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_ROUTE134_water_mons), sWeighted_ROUTE134_water_mons},
    {84, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_LILYCOVE_CITY_water_mons), sWeighted_LILYCOVE_CITY_water_mons},
    {85, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_DEWFORD_TOWN_water_mons), sWeighted_DEWFORD_TOWN_water_mons},
    {86, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_SLATEPORT_CITY_water_mons), sWeighted_SLATEPORT_CITY_water_mons},
    {87, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_MOSSDEEP_CITY_water_mons), sWeighted_MOSSDEEP_CITY_water_mons},
    {88, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_PACIFIDLOG_TOWN_water_mons), sWeighted_PACIFIDLOG_TOWN_water_mons},
    {89, WILD_AREA_WATER, ARRAY_COUNT(sWeighted_EVER_GRANDE_CITY_water_mons), sWeighted_EVER_GRANDE_CITY_water_mons},
};
