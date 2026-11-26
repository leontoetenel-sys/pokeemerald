SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applywaitmovement LOCALID_DOCK, Common_Movement_FacePlayer
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Hmm... Dit moet hier en dat daar.\p"
	.string "Maar waar moet dit ding dan?\n"
	.string "En dat andere ding?\p"
	.string "Aaargh! Ik snap er niets van!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hm? Hallo, ik ben DOCK.\p"
	.string "Kapitein STERN vroeg mij\n"
	.string "een veerboot te ontwerpen.\p"
	.string "O! Zijn dat de DEVON GOODS?\p"
	.string "Kapitein STERN is ergens heen.\n"
	.string "Hij had nog werk te doen.\p"
	.string "Wil jij hem zoeken en\n"
	.string "het pakket aan hem geven?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "DOCK: Waar is kapitein STERN toch?\p"
	.string "Wil jij hem zoeken en\n"
	.string "het pakket aan hem geven?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "DOCK: Schepen bouwen is een kunst.\p"
	.string "Je kunt niet alles uitrekenen.\p"
	.string "Ik kan wel hulp gebruiken van\n"
	.string "iemand die de zee goed kent.$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "DOCK: Meneer BRINEY helpt ons nu!\p"
	.string "Dankzij deze ervaren zeeman\n"
	.string "schiet de bouw goed op.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK: De veerboot is eindelijk af!\p"
	.string "De S.S. TIDAL is een prachtig schip.\p"
	.string "Toch denk ik dat we ooit\n"
	.string "een nog beter schip kunnen maken.\p"
	.string "Techniek blijft zich ontwikkelen!$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "Meneer BRINEY: Ah, {PLAYER}!\n"
	.string "Lang niet gezien!\p"
	.string "Sinds ik jou ken, voel ik me\n"
	.string "weer helemaal jong!\p"
	.string "Ik help DOCK een veerboot bouwen.\n"
	.string "Daar kunnen veel mensen op mee.\p"
	.string "DOCK is heel goed met techniek.\n"
	.string "Ik weet veel van de zee.\p"
	.string "Samen bouwen we een prachtig schip!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "De seizoenen, het weer en\n"
	.string "de maan veranderen de zee.\p"
	.string "De zee lijkt wel een levend wezen!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Ik word snel zeeziek.\n"
	.string "Daarom help ik liever hier.$"

