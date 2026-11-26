RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Mijn Pokémon heeft de NAIVE nature.\n"
	.string "Die van mijn vriend is JOLLY.\p"
	.string "Leuk dat Pokémon allemaal\n"
	.string "een eigen karakter hebben!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Net als mensen zijn er mannelijke\n"
	.string "en vrouwelijke Pokémon.\p"
	.string "Maar niemand lijkt precies te\n"
	.string "weten wat de verschillen zijn.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "De man hiernaast gaf me een HM!\p"
	.string "Nu kan mijn Pokémon met CUT\n"
	.string "dunne boompjes omhakken.$"

