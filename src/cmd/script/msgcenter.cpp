/* 
 * Vega Strike
 * Copyright (C) 2001-2002 Daniel Horn
 * 
 * http://vegastrike.sourceforge.net/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/*
  MessageCenter written by Alexander Rawass <alexannika@users.sourceforge.net>
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#ifndef WIN32
// this file isn't available on my system (all win32 machines?) i dun even know what it has or if we need it as I can compile without it
#include <unistd.h>
#endif

#include <expat.h>
#include "xml_support.h"

#include "vegastrike.h"

#include "mission.h"
#include "easydom.h"

#include "msgcenter.h"

//#include "vs_globals.h"
//#include "vegastrike.h"

void MessageCenter::add(string from,string to,string message){
  gameMessage *msg=new gameMessage();
  
  msg->from=from;
  msg->to=to;
  msg->message=message;

  msg->ufrom=NULL;
  msg->uto=NULL;

  //  msg->time=gametime;

  messages.push_back(msg);
}

gameMessage *MessageCenter::last(uint n){
  int size=messages.size();

  int index=size-1-n;

  if(index>=0){
    return messages[index];
  }
  else{
    return NULL;
  }
}
