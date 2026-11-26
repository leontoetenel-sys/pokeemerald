VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applywaitmovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applywaitmovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Mijn papa vertelde het me.\p"
	.string "In deze tunnel wonen heel\n"
	.string "verlegen Pokémon.\p"
	.string "Ze schrikken van harde geluiden\n"
	.string "en raken helemaal in paniek.\p"
	.string "Daarom moesten ze stoppen\n"
	.string "met het graven van de tunnel.\p"
	.string "Maar één man probeert de tunnel\n"
	.string "helemaal zelf te graven!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Een man groef een tunnel voor\n"
	.string "de vrouw van wie hij hield.\p"
	.string "Ik snap het niet helemaal, hoor!$"

VerdanturfTown_Text_AirCleanHere:
	.string "Door de wind komt er nooit\n"
	.string "vulkanische as deze kant op.\p"
	.string "De lucht is hier schoon en fris.\n"
	.string "Zelfs zieke mensen knappen\l"
	.string "hier helemaal op.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Mijn Pokémon en ik winnen\n"
	.string "het ene duel na het andere.\p"
	.string "Daarom doe ik hier voor het\n"
	.string "eerst mee in de BATTLE TENT.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Zag je de grot naast de\n"
	.string "Pokémon MART?\p"
	.string "Een man probeert daar rotsen\n"
	.string "kapot te maken om aan de\l"
	.string "andere kant te komen.\p"
	.string "Dan kunnen we makkelijk naar\n"
	.string "RUSTBORO! Dat zou fijn zijn.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "De grot naast de Pokémon MART\n"
	.string "is nu een tunnel geworden.\p"
	.string "Nu kunnen we makkelijk naar\n"
	.string "RUSTBORO voor DEVON-producten!$"

VerdanturfTown_Text_TownSign:
	.string "VERDANTURF TOWN\p"
	.string "De winderige heuvels met\n"
	.string "de heerlijke geur van gras.$"

VerdanturfTown_Text_WandasHouse:
	.string "HUIS VAN WANDA$"

VerdanturfTown_Text_BattleTentSign:
	.string "BATTLE TENT VERDANTURF\n"
	.string "Geniet van spannende duels!$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "RUSTURF TUNNEL\n"
	.string "Verbindt RUSTBORO en VERDANTURF.\p"
	.string "De aanleg is stopgezet.$"

