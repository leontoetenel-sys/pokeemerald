OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Die PC daar in de hoek is\n"
	.string "voor alle Pokémon-trainers.\p"
	.string "Jij mag hem dus ook gebruiken!$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "Pokémon Centers zijn geweldig!\p"
	.string "Je mag zo vaak komen als je wilt.\n"
	.string "En alles is gratis!\p"
	.string "Je hoeft je geen zorgen te maken.$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "De POKéMON WIRELESS CLUB boven\n"
	.string "is pas gebouwd.\p"
	.string "Maar ze zijn nog bezig\n"
	.string "met de laatste aanpassingen.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "De POKéMON WIRELESS CLUB boven\n"
	.string "is pas gebouwd.\p"
	.string "Ik heb meteen Pokémon geruild!$"

