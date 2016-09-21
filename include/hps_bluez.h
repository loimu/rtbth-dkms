/*
*************************************************************************
* Ralink Technology Corporation
* 5F., No. 5, Taiyuan 1st St., Jhubei City,
* Hsinchu County 302,
* Taiwan, R.O.C.
*
* (c) Copyright 2012, Ralink Technology Corporation
*
* This program is free software; you can redistribute it and/or modify  *
* it under the terms of the GNU General Public License as published by  *
* the Free Software Foundation; either version 2 of the License, or     *
* (at your option) any later version.                                   *
*                                                                       *
* This program is distributed in the hope that it will be useful,       *
* but WITHOUT ANY WARRANTY; without even the implied warranty of        *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
* GNU General Public License for more details.                          *
*                                                                       *
* You should have received a copy of the GNU General Public License     *
* along with this program; if not, write to the                         *
* Free Software Foundation, Inc.,                                       *
* 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
*                                                                       *
*************************************************************************/

#ifndef __HPS_BLUEZ_H
#define __HPS_BLUEZ_H


#include <net/bluetooth/bluetooth.h>
#include <net/bluetooth/hci_core.h>
#include "rt_linux.h"


/* 
	Following three definitions are defined in kernelSrc/include/net/bluetooth/hci.h,
	But our code also has typedef enum for these three constants, so we undefine it 
	here to make compile.

	For two module cases, this can ignore it.
*/
#undef SCO_LINK
#undef ACL_LINK
#undef ESCO_LINK

struct rtbt_os_ctrl;


int rtbt_hps_iface_init(int if_type, void *if_dev, struct rtbt_os_ctrl *ctrl);
int rtbt_hps_iface_deinit(int if_type, void *if_dev, struct rtbt_os_ctrl *os_ctrl);

int rtbt_hps_iface_suspend(IN struct rtbt_os_ctrl *os_ctrl);
int rtbt_hps_iface_resume(IN struct rtbt_os_ctrl *os_ctrl);

int rtbt_hps_iface_attach(struct rtbt_os_ctrl *os_ctrl);
int rtbt_hps_iface_detach(struct rtbt_os_ctrl *os_ctrl);

	
#endif // __HPS_BLUEZ_H //

