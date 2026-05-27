// Fill out your copyright notice in the Description page of Project Settings.


#include "SessionItemWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void USessionItemWidget::SetInfo(FBlueprintSessionResult InSessionResult)
{
	Result = InSessionResult;

	RefreshUI();
}

void USessionItemWidget::RefreshUI()
{
	// 방이름 담아줄 변수
	FString SessionName;
	// 세션세팅에 넣어놨던 방이름 가져오기
	Result.OnlineResult.Session.SessionSettings.Get("SESSION_NAME", OUT SessionName);

	// 방이름 설정하기
	Txt_SessionName->SetText(FText::FromString(SessionName));


	FString MapName;
	Result.OnlineResult.Session.SessionSettings.Get("MAP_NAME", OUT MapName);

	Txt_MapName->SetText(FText::FromString(MapName));


	const int32 currentPlayers = Result.OnlineResult.Session.SessionSettings.NumPublicConnections -
		Result.OnlineResult.Session.NumOpenPublicConnections;
	const int32 MaxPlayers = Result.OnlineResult.Session.SessionSettings.NumPublicConnections;
	FString PlayerCountString = FString::Printf(TEXT("(%d / %d)"), currentPlayers, MaxPlayers);

	Txt_PlayerCount->SetText(FText::FromString(PlayerCountString));
}