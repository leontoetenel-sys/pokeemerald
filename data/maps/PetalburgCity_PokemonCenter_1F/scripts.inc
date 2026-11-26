PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Dat opslagsysteem voor Pokémon\n"
	.string "op de PC...\p"
	.string "De uitvinder moet wel een\n"
	.string "wetenschappelijk genie zijn!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Mijn Pokémon at een ORAN BERRY\n"
	.string "en kreeg er HP bij!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Er zijn veel Pokémon-types.\p"
	.string "Elk type heeft sterke en\n"
	.string "zwakke kanten tegen andere types.\p"
	.string "De types bepalen mede hoe\n"
	.string "makkelijk een duel wordt.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Jouw TREECKO is bijvoorbeeld\n"
	.string "een GRASS-type.\p"
	.string "Sterk tegen WATER en GROUND.\p"
	.string "Maar zwak tegen FIRE-type\n"
	.string "Pokémon.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Jouw TORCHIC is bijvoorbeeld\n"
	.string "een FIRE-type.\p"
	.string "Sterk tegen GRASS en BUG.\p"
	.string "Maar zwak tegen WATER-type\n"
	.string "Pokémon.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Jouw MUDKIP is bijvoorbeeld\n"
	.string "een WATER-type.\p"
	.string "Sterk tegen FIRE.\p"
	.string "Maar zwak tegen GRASS en\n"
	.string "ELECTRIC-type Pokémon.$"

