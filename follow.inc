#event FollowToggle "[#1#] follow"
#event FollowToggle "<#1#> follow"

Sub event_FollowToggle(line, ChatSender, eventParams)
	/if (!${Bool[${Spawn[pc ${MainAssist}]}]}) {
		/bc I don't see ${MainAssist} in zone to follow
		/return
	}
	/if (${ChatSender.Equal[${Me.Name}]}) /return	
	/if (${IsPredator}) /varset IsPredator FALSE
	/if (${Me.Sitting}) /sit off
	/if (!${Stick.Active} && !${MainAssist.Equal[${Me.Name}]}) {
		/stick 10 id ${Spawn[pc ${MainAssist}].ID}
		/return
	}

	/if (${Main.Assist.Equal[${MainPuller}]}) /return		
	/if (!${Stick.Active}) /stick 10 id ${Spawn[pc ${MainPuller}].ID}
/return