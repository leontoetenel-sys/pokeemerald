DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applywaitmovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applywaitmovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Wat is populair? Natuurlijk\n"
	.string "{STR_VAR_1}!\p"
	.string "Ik kan niet meer zonder!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Wat is populair? Natuurlijk\n"
	.string "{STR_VAR_1}!\p"
	.string "Maar ik begin het saai te vinden.\n"
	.string "Tijd voor iets nieuws!$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "Ik leer mijn POKéMON alles over\n"
	.string "{STR_VAR_1}.\p"
	.string "Maar hij snapt het nog niet.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "Ik leer alles over {STR_VAR_1}.\p"
	.string "Is er echt een verband tussen\n"
	.string "{STR_VAR_1} en {STR_VAR_2}?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "O! Ik had dus gelijk!\p"
	.string "Nu ben ik weer wat hipper!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Wat? Echt waar?\p"
	.string "Voor een oude man als ik is het\n"
	.string "lastig om bij te blijven!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Over {STR_VAR_1} gesproken...\p"
	.string "Is daar geen tv-programma over?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "Aan de overkant van de zee...\p"
	.string "Is {STR_VAR_1} daar nog populairder?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Ik verzamel alles van\n"
	.string "{STR_VAR_1}.\p"
	.string "Ik heb poppen, kleding en\n"
	.string "prentenboeken!\p"
	.string "Hihi! Alles is van mij!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "Hier staan allemaal boeken over\n"
	.string "{STR_VAR_1}.\p"
	.string "Over goede en slechte voorbeelden,\n"
	.string "en over POKéMON.$"

DewfordTown_Hall_Text_TrendsScream:
	.string "Dit boek heet: De schreeuw van\n"
	.string "{STR_VAR_1}.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "Dit boek heet: De glimlach van\n"
	.string "{STR_VAR_1}.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Dit boek heet: De laatste\n"
	.string "{STR_VAR_1}.$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Dit boek heet: De geboorte van\n"
	.string "{STR_VAR_1}.$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "Ik heb {STR_VAR_1} gezien!\p"
	.string "Supercool! Het was echt geweldig!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Nee, nee, nee!\p"
	.string "Wat jij zag was niet de echte\n"
	.string "{STR_VAR_1}.\p"
	.string "De echte is veel bijzonderder!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Ik heb een lied gemaakt over\n"
	.string "{STR_VAR_1}!\p"
	.string "Luister maar!\p"
	.string "O, {STR_VAR_1}!\n"
	.string "Prachtige {STR_VAR_1}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "... ...\p"
	.string "Misschien moet je eerst nog\n"
	.string "wat oefenen met zingen.$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "We moeten samen een feest\n"
	.string "organiseren op het eiland.\p"
	.string "Een {STR_VAR_1}-feest!$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Wat een geweldig idee!\p"
	.string "Dan weten we eindelijk wie\n"
	.string "de beste is in {STR_VAR_1}!\p"
	.string "Vanaf vandaag draait alles\n"
	.string "om {STR_VAR_1}!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "Ik zat te denken...\p"
	.string "{STR_VAR_1} is niet zomaar\n"
	.string "een rage meer.\p"
	.string "Het hoort nu bij ons leven!$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Wat zeg je?\p"
	.string "Je denkt dag en nacht aan\n"
	.string "{STR_VAR_1}.\p"
	.string "Jij bent echt de professor\n"
	.string "van {STR_VAR_1}!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Als wij samenwerken, kan niemand\n"
	.string "ons verslaan met {STR_VAR_1}!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Precies, vriend!\p"
	.string "Wij worden het {STR_VAR_1}-duo!\p"
	.string "Hahaha!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Ik vind SLUDGE BOMB de beste!\p"
	.string "Ken je die aanval niet?\p"
	.string "Dan geef ik je er eentje!$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "Ik hou van SLUDGE BOMB.\p"
	.string "Maar POKéMON met {STR_VAR_1}\n"
	.string "zijn ook populair.$"

