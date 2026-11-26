MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applywaitmovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	playse SE_PIN
	applywaitmovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	return

MtChimney_EventScript_ArchieExitEast::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	return

MtChimney_EventScript_ArchieExitNorth::
	applywaitmovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "De kracht in deze METEORITE...\p"
	.string "Met deze machine versterken\n"
	.string "we die kracht. Dan wordt de\l"
	.string "vulkaan meteen veel actiever!\p"
	.string "Diep in de krater zal de\n"
	.string "energie steeds groter worden...\l"
	.string "Hehehe...$"

MtChimney_Text_MaxieIntro:
	.string "MAXIE: Hm?\n"
	.string "Wie ben jij?\p"
	.string "... ... ... ... ... ...\n"
	.string "... ... ... ... ... ...\p"
	.string "Ik hoorde ARCHIE klagen over\n"
	.string "een kind dat TEAM AQUA\l"
	.string "steeds in de weg zit.\p"
	.string "Hij bedoelde vast jou.\p"
	.string "Hm! Wil je nu ook de plannen\n"
	.string "van TEAM MAGMA dwarsbomen?\p"
	.string "Luister goed.\n"
	.string "Lang geleden leefden en\l"
	.string "groeiden wezens op het land.\p"
	.string "Daarom is land zo belangrijk!\n"
	.string "Het is de basis van al het leven!\p"
	.string "Daarom wil TEAM MAGMA\n"
	.string "steeds meer land maken.\p"
	.string "Zo kunnen mensen en Pokémon\n"
	.string "zich verder ontwikkelen!\p"
	.string "Daarvoor hebben we de kracht\n"
	.string "nodig van wat in deze berg slaapt.\p"
	.string "O! Eigenlijk hoefde jij dat\n"
	.string "allemaal niet te weten.\p"
	.string "Maar dat maakt niet uit!\n"
	.string "Ik zal je leren wat er gebeurt\l"
	.string "als je onze plannen dwarsboomt!$"

MtChimney_Text_MaxieDefeat:
	.string "Wat?!\p"
	.string "Heb jij mij, MAXIE, verrast?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAXIE: Genoeg.\n"
	.string "Deze keer trek ik me terug.\p"
	.string "Maar denk niet dat je TEAM MAGMA\n"
	.string "voor het laatst hebt gezien.\p"
	.string "Hehehe...\p"
	.string "Zelfs zonder de METEORITE,\n"
	.string "als we die ORB bemachtigen...\l"
	.string "Hehehe...$"

MtChimney_Text_TabithaIntro:
	.string "Hehehe!\p"
	.string "Dus je bent helemaal hierheen\n"
	.string "gekomen!\p"
	.string "Maar je bent te laat!\n"
	.string "Ik heb de METEORITE uit\l"
	.string "METEOR FALLS al aan de BAAS\l"
	.string "gegeven!$"

MtChimney_Text_TabithaDefeat:
	.string "Hehehe...\p"
	.string "Ook al heb ik verloren, als\n"
	.string "onze leider dat ding wekt...$"

MtChimney_Text_TabithaPostBattle:
	.string "BAAS, schiet op!\n"
	.string "Geef het de energie van de\l"
	.string "METEORITE!\p"
	.string "Hehehe...$"

MtChimney_Text_Grunt2Intro:
	.string "Wij van TEAM MAGMA werken\n"
	.string "hard om iedereen te helpen.\p"
	.string "Met de kracht van dat ding\n"
	.string "kunnen we meer land maken.\p"
	.string "Dan is er meer ruimte om te\n"
	.string "wonen. Iedereen wordt blij!$"

MtChimney_Text_Grunt2Defeat:
	.string "Hè?\n"
	.string "Hoezo heb ik verloren?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Onze BAAS zegt dat iedereen\n"
	.string "er blij van wordt.\p"
	.string "Waarom blijft iedereen ons\n"
	.string "dan tegenwerken?$"

MtChimney_Text_Grunt1Intro:
	.string "Als er meer land was, kon ik\n"
	.string "een groot eigen huis krijgen!\p"
	.string "Ik bouw het op gestolde lava!$"

MtChimney_Text_Grunt1Defeat:
	.string "Mijn droom van een groot huis...$"

MtChimney_Text_Grunt1PostBattle:
	.string "Een kind zoals jij hoort toch\n"
	.string "lekker in de golven te spelen!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Dat vervelende TEAM AQUA...\n"
	.string "Ze verpesten altijd onze plannen!$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "METEORITES hebben een\n"
	.string "geweldige kracht!$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Je kunt ons beter niet storen!\p"
	.string "We proberen dat ding te wekken\n"
	.string "om iedereen te helpen!$"

MtChimney_Text_AquasNameSimilar:
	.string "Wij zijn TEAM MAGMA!\p"
	.string "Zij zijn TEAM AQUA!\p"
	.string "Ik vind het zo irritant dat\n"
	.string "hun naam op die van ons lijkt!$"

MtChimney_Text_DouseThemInFire:
	.string "Ja!\n"
	.string "Overgiet ze met vuur!$"

MtChimney_Text_KeepMakingMoreLand:
	.string "We blijven steeds meer land\n"
	.string "maken!$"

MtChimney_Text_Bufoh:
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARCHIE: Grr, {PLAYER}!\n"
	.string "Ik had je hier kunnen verwachten!\p"
	.string "Kijk zelf maar wat die gekken\n"
	.string "van TEAM MAGMA van plan zijn!\p"
	.string "Ze willen de kracht van de\n"
	.string "gestolen METEORITE in de\l"
	.string "vulkaan stoppen!\p"
	.string "Daarmee laten ze de vulkaan\n"
	.string "uitbarsten!$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIE: Grrr...\p"
	.string "Ik wil MAXIE tegenhouden,\n"
	.string "maar dat lukt me niet!\p"
	.string "Ik moet tegen drie vijanden\n"
	.string "tegelijk vechten!$"

MtChimney_Text_ArchieThankYou:
	.string "ARCHIE: {PLAYER}!\n"
	.string "Bedankt!\p"
	.string "Dankzij jou hebben we het\n"
	.string "gevaarlijke plan van TEAM MAGMA\l"
	.string "verijdeld!\p"
	.string "Maar... Jij...\n"
	.string "Aan welke kant sta jij eigenlijk?\p"
	.string "Ach, het maakt niet uit.\p"
	.string "We blijven opletten en gaan\n"
	.string "verder achter TEAM MAGMA aan.\p"
	.string "{PLAYER}, tot de volgende keer!$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Verdorie! TEAM MAGMA is\n"
	.string "met meer mensen dan wij!\p"
	.string "We kunnen ze niet bijhouden!$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "Als ze meer land maken, blijft\n"
	.string "er minder leefruimte over\l"
	.string "voor WATER-type Pokémon!$"

MtChimney_Text_MagmasNameSimilar:
	.string "Wij zijn TEAM AQUA!\p"
	.string "Zij zijn TEAM MAGMA!\p"
	.string "Ik word zo boos van die\n"
	.string "verwarrende naam!$"

MtChimney_Text_Bushaa:
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200:
	.string "LAVA COOKIES zijn de specialiteit\n"
	.string "van MT. CHIMNEY.\p"
	.string "Proef er eentje voor maar ¥200.$"

MtChimney_Text_ThankYouDear:
	.string "Dank je wel, lieverd!$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Ach, lieverd. Zonder geld\n"
	.string "kun je niets kopen.$"

MtChimney_Text_OhFineThen:
	.string "O, ook goed.$"

MtChimney_Text_MeteoriteFittedOnMachine:
	.string "Er zit een METEORITE op een\n"
	.string "mysterieuze machine...\p"
	.string "De machine lijkt energie in\n"
	.string "de METEORITE op te slaan.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Er zit een METEORITE op een\n"
	.string "mysterieuze machine...\p"
	.string "Wil je de METEORITE weghalen?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} haalde de METEORITE\n"
	.string "van de mysterieuze machine.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} liet de METEORITE\n"
	.string "zitten.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Deze mysterieuze machine...\n"
	.string "Hij reageert helemaal niet.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} JAGGED PATH\n"
	.string "Verder naar LAVARIDGE TOWN$"

MtChimney_Text_ShelbyIntro:
	.string "Ik ben in de warme bronnen\n"
	.string "geweest. Mijn oude botten\l"
	.string "voelen weer heerlijk!\p"
	.string "Ik voel me nu sterk!$"

MtChimney_Text_ShelbyDefeat:
	.string "O, mijn hemel.\n"
	.string "Wat ben jij toch goed!$"

MtChimney_Text_ShelbyPostBattle:
	.string "Nou, nou, ik heb verloren.\n"
	.string "Ik kan mezelf geen EXPERT\l"
	.string "meer noemen, hè?$"

MtChimney_Text_ShelbyRegister:
	.string "Bedankt, kind. Het was leuk,\n"
	.string "alsof ik tegen mijn eigen\l"
	.string "kleinkind vocht.\p"
	.string "Kom gerust terug voor\n"
	.string "een nieuw duel.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Als jouw hart en dat van je\n"
	.string "Pokémon samen één worden,\l"
	.string "kun je geweldige dingen doen.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "O, mijn hemel.\n"
	.string "Wat ben jij toch goed!$"

MtChimney_Text_ShelbyPostRematch:
	.string "Misschien is jouw hart nu één\n"
	.string "met dat van je Pokémon.$"

MtChimney_Text_MelissaIntro:
	.string "Het vuur brandt in mij!\n"
	.string "Ik kan niet wachten!\l"
	.string "Ik moet vechten!$"

MtChimney_Text_MelissaDefeat:
	.string "Oeh, dat was een gloeiend\n"
	.string "heet duel!$"

MtChimney_Text_MelissaPostBattle:
	.string "De hitte van MT. CHIMNEY\n"
	.string "maakt me lekker warm!$"

MtChimney_Text_SheilaIntro:
	.string "Ik ben eindelijk bij MT. CHIMNEY.\n"
	.string "Ik wil met mijn Pokémon vechten!$"

MtChimney_Text_SheilaDefeat:
	.string "De manier waarop jij vecht...\n"
	.string "Net een vulkaanuitbarsting!$"

MtChimney_Text_SheilaPostBattle:
	.string "Ik ben eindelijk bij MT. CHIMNEY.\n"
	.string "Het zou zonde zijn om alleen\l"
	.string "maar rond te kijken.\p"
	.string "Ik wil wat duels houden en\n"
	.string "LAVA COOKIES als souvenir kopen.$"

MtChimney_Text_ShirleyIntro:
	.string "Sinds ik in de warme bronnen\n"
	.string "ben geweest, voel ik me prima!\p"
	.string "Ik weet zeker dat ik win!$"

MtChimney_Text_ShirleyDefeat:
	.string "Au!\n"
	.string "Ik krijg het koud buiten het water.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Ik moet nog eens in de warme\n"
	.string "bron duiken. Ga je mee?\p"
	.string "Grapje!$"

MtChimney_Text_SawyerIntro:
	.string "Wat een fijne berg!\n"
	.string "Allemaal vurige mensen hier!$"

MtChimney_Text_SawyerDefeat:
	.string "O, jij bent ook een echte\n"
	.string "vuurbol!$"

MtChimney_Text_SawyerPostBattle:
	.string "Ik denk dat ik met de mensen\n"
	.string "uit LAVARIDGE in de warme\l"
	.string "bron ga zitten!$"

MtChimney_Text_SawyerRegister:
	.string "Ik hou van vuurbolletjes als jij.\n"
	.string "Ik registreer je in mijn PokéNav.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Ik ben hier omringd door\n"
	.string "vurige mensen. Ik verlies niet!$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Je bent nog steeds zo'n\n"
	.string "vuurbol als vroeger!$"

MtChimney_Text_SawyerPostRematch:
	.string "Eigenlijk is het hier echt heet.\n"
	.string "Ik heb veel te warme kleren aan.$"

