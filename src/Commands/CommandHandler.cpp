// This file is part of BowPad.
//
// Copyright (C) 2013 - Stefan Kueng
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// See <http://www.gnu.org/licenses/> for a copy of the full license text
//
#include "stdafx.h"
#include "CommandHandler.h"

#include "CmdMRU.h"
#include "CmdFiles.h"
#include "CmdUndo.h"
#include "CmdClipboard.h"
#include "CmdLineWrap.h"
#include "CmdWhiteSpace.h"
#include "CmdLoadEncoding.h"
#include "CmdCodeStyle.h"
#include "CmdEOL.h"
#include "CmdPrevNext.h"
#include "CmdFindReplace.h"
#include "CmdMisc.h"
#include "CmdStyleConfigurator.h"
#include "CmdVerticalEdge.h"
#include "CmdComment.h"
#include "CmdConvertCase.h"
#include "CmdLines.h"
#include "CmdPrint.h"
#include "CmdGotoLine.h"
#include "CmdSelectTab.h"
#include "CmdBlanks.h"
#include "CmdZoom.h"

CCommandHandler::CCommandHandler(void)
{
}


CCommandHandler::~CCommandHandler(void)
{
    for (auto c:m_commands)
    {
        delete c.second;
    }
}

CCommandHandler& CCommandHandler::Instance()
{
    static CCommandHandler instance;
    return instance;
}

ICommand * CCommandHandler::GetCommand( UINT cmdId )
{
    auto c = m_commands.find(cmdId);
    if (c != m_commands.end())
        return c->second;

    return nullptr;
}

void CCommandHandler::Init( void * obj )
{
    ICommand * pCmd = new CCmdMRU(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdOpen(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdSave(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdSaveAll(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdSaveAs(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdReload(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdPrint(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdPrintNow(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdPageSetup(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdUndo(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdRedo(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdCut(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdCopy(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdPaste(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdDelete(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdSelectAll(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdLineWrap(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdWhiteSpace(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdUseTabs(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdTabSize(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdLoadAsEncoded(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdConvertEncoding(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdCodeStyle(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdStyleConfigurator(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;

    pCmd = new CCmdEOLWin(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdEOLUnix(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdEOLMac(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;

    pCmd = new CCmdPrevNext(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdPrevious(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdNext(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;

    pCmd = new CCmdFindReplace(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdFindNext(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdFindPrev(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdFindSelectedNext(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdFindSelectedPrev(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdGotoLine(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;

    pCmd = new CCmdVerticalEdge(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;

    pCmd = new CCmdComment(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdUnComment(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdConvertUppercase(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdConvertLowercase(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;

    pCmd = new CCmdLineDuplicate(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdLineSplit(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdLineJoin(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdLineUp(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdLineDown(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;

    pCmd = new CCmdTrim(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdTabs2Spaces(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdSpaces2Tabs(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;

    pCmd = new CCmdSelectTab(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdZoom100(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdZoomIn(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
    pCmd = new CCmdZoomOut(obj);
    m_commands[pCmd->GetCmdId()] = pCmd;
}

void CCommandHandler::ScintillaNotify( Scintilla::SCNotification * pScn )
{
    for (auto cmd:m_commands)
    {
        cmd.second->ScintillaNotify(pScn);
    }
}

void CCommandHandler::TabNotify( TBHDR * ptbhdr )
{
    for (auto cmd:m_commands)
    {
        cmd.second->TabNotify(ptbhdr);
    }
}
