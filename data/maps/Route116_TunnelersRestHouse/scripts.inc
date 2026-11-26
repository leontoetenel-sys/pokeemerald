Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Die RUSTURF TUNNEL daar...\p"
	.string "Eerst groeven we met een grote\n"
	.string "ploeg en moderne machines\l"
	.string "door de rotsen.\p"
	.string "Maar we moesten stoppen.\p"
	.string "Het bleek dat we de wilde\n"
	.string "Pokémon in dit gebied zouden\l"
	.string "verstoren.\p"
	.string "Nu hebben we niets te doen\n"
	.string "en hangen we hier maar rond.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Er is een man die helemaal\n"
	.string "alleen naar VERDANTURF graaft.\p"
	.string "Hij wil er heel graag naartoe.\p"
	.string "Hij zegt dat hij de Pokémon\n"
	.string "niet stoort als hij langzaam\l"
	.string "en zonder machines graaft.\p"
	.string "Zo beschadigt hij de natuur\n"
	.string "ook niet.\p"
	.string "Zou hij al aan de overkant zijn?$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Wil je zonder deze tunnel\n"
	.string "naar VERDANTURF?\p"
	.string "Dan moet je over zee naar\n"
	.string "DEWFORD, verder naar SLATEPORT\l"
	.string "en dan via MAUVILLE reizen.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Heb je het gehoord? De tunnel\n"
	.string "naar VERDANTURF is open!\p"
	.string "Soms komen dromen echt uit\n"
	.string "als je maar hard genoeg hoopt.$"

