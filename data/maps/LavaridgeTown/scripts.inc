LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	playse SE_PIN
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	closedoor 12, 15
	waitdooranim
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	playse SE_PIN
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applywaitmovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "MAY: {PLAYER}! Lang niet gezien!\p"
	.string "O? Terwijl ik in de warme\n"
	.string "bronnen zat, heb jij de BADGE\l"
	.string "van LAVARIDGE gewonnen!\p"
	.string "Je hebt vast goede Pokémon\n"
	.string "gevangen...\l"
	.string "Nee, je hebt ze goed getraind.\p"
	.string "Ik denk dat jij dit wel\n"
	.string "mag hebben.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "MAY: Met die GO-GOGGLES kun\n"
	.string "je zonder problemen door de\l"
	.string "woestijn bij ROUTE 111.\p"
	.string "Maar wauw, {PLAYER}...\n"
	.string "Je daagt allemaal GYMS uit!\p"
	.string "Je doet vast zo je best omdat\n"
	.string "je niet van mij wilt verliezen!\p"
	.string "{PLAYER}, ik denk dat ik je papa\n"
	.string "ga uitdagen in PETALBURG GYM.\p"
	.string "Tot ziens!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRENDAN: Hé, {PLAYER}!\n"
	.string "Lang niet gezien. Hoe gaat het?\p"
	.string "Hmm... Je hebt al een mooie\n"
	.string "verzameling BADGES.\p"
	.string "Goed dan.\n"
	.string "Neem dit maar mee.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRENDAN: Neem die mee als je\n"
	.string "naar de woestijn bij ROUTE 111\l"
	.string "gaat.\p"
	.string "Daar leven vast Pokémon die\n"
	.string "alleen in de woestijn voorkomen.\p"
	.string "Ga maar eens op zoek!\p"
	.string "En ik? Ik denk dat ik NORMAN,\n"
	.string "de Gymleider van PETALBURG,\l"
	.string "ga uitdagen.\p"
	.string "In tegenstelling tot jou lijkt\n"
	.string "je papa me echt sterk, {PLAYER}.\p"
	.string "Tot ziens!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "Ik heb hier een EGG.\p"
	.string "Ik hoopte dat het zou uitkomen\n"
	.string "in het warme zand bij de bron.\p"
	.string "Maar dat lijkt niet genoeg.\p"
	.string "Ik hoorde dat je het beter\n"
	.string "bij je Pokémon kunt houden\l"
	.string "en ermee rond kunt lopen.\p"
	.string "Jij bent een trainer, toch?\n"
	.string "Je Pokémon zitten vol energie!\p"
	.string "Wat denk je? Wil jij dit EGG\n"
	.string "laten uitkomen?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Mooi! Ik hoop dat je veel\n"
	.string "gaat wandelen met dit EGG!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} kreeg het EGG.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "O? Je hebt te veel Pokémon.\n"
	.string "Er is geen plek voor dit EGG...$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Zoals je wilt...\p"
	.string "Als je toch dit EGG wilt laten\n"
	.string "uitkomen, ben ik hier.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Af en toe wordt er een EGG\n"
	.string "gevonden bij de DAY CARE.\p"
	.string "Tenminste, dat zeggen ze.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "We halen zoveel warm water\n"
	.string "als we nodig hebben, maar de\l"
	.string "bronnen raken nooit leeg.\p"
	.string "Is dat niet bijzonder?\p"
	.string "Deze bronnen ontstaan bij\n"
	.string "actieve vulkanen.\p"
	.string "Magma verwarmt het water\n"
	.string "onder de grond. Zo komt het\l"
	.string "als warm bronwater omhoog.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "In dit warme zand liggen is...\n"
	.string "Zucht...\p"
	.string "Zo heerlijk warm...\p"
	.string "Hè? Aaaah! Au!\p"
	.string "Een Pokémon beet in mijn billen!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "O, hou jij van warme bronnen?\p"
	.string "Dat verbaast me, zo jong als\n"
	.string "jij nog bent.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Ik ga elke dag in de warme bron.\p"
	.string "Ik wil een mooie, sterke\n"
	.string "Gymleider worden zoals FLANNERY.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Als mensen hun Pokémon in de\n"
	.string "warme bron laten, wordt het\l"
	.string "misschien een vreemd bad.\p"
	.string "Een elektrisch bad, een bubbelbad\n"
	.string "of zelfs een lavabad...$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "Ze zeggen dat deze bronnen\n"
	.string "helpen tegen spanning en\l"
	.string "pijnlijke spieren.\p"
	.string "En zelfs bij liefdesproblemen\n"
	.string "en om geld aan te trekken...$"

LavaridgeTown_Text_TownSign:
	.string "LAVARIDGE TOWN\p"
	.string "WARME BRONNEN POKéMON CENTER\n"
	.string "Een heerlijke plek om te rusten!$"

LavaridgeTown_Text_GymSign:
	.string "LAVARIDGE TOWN POKéMON GYM\n"
	.string "GYMLEIDER: FLANNERY\l"
	.string "Vol vurige passie!$"

LavaridgeTown_Text_HerbShopSign:
	.string "POKéMON KRUIDENWINKEL\n"
	.string "Bitter van smaak, goed herstel!$"

