Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Ik ben de fossielenfan...\n"
	.string "Ik ben aardig en dol op fossielen.\p"
	.string "Wil je een fossiel?\p"
	.string "Alle fossielen hier zijn van mij.\n"
	.string "Geen eentje voor jou...\p"
	.string "Wil je echt een fossiel vinden?\n"
	.string "Zoek dan in een woestijn.\p"
	.string "Tussen de rotsen en het zand\n"
	.string "kunnen fossielen verstopt liggen.$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Je hebt een fossiel gevonden, hè?\n"
	.string "Wat mooi... Wat een droom...\p"
	.string "Wat ga je ermee doen?\p"
	.string "Ik hoorde dat DEVON onderzoekt\n"
	.string "hoe je Pokémon uit fossielen\l"
	.string "weer tot leven kunt brengen.\p"
	.string "Ik hou van mijn fossielen.\n"
	.string "Ik zou dat nooit doen...$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "Fossielen zijn zo... geweldig...\n"
	.string "Wat een droom...$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "O... Die kant is niet veilig.\p"
	.string "Ik was aan het graven toen\n"
	.string "de hele muur instortte...\p"
	.string "Volgens mij ligt er nu een\n"
	.string "enorme grot onder de grond.\p"
	.string "Ik laat die met rust. Volgens\n"
	.string "mij liggen daar geen fossielen.$"

