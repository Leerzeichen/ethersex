/* vim:fdm=marker ts=4 et ai
 * {{{
 *
 * (c) by Alexander Neumann <alexander@bumpern.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * For more information on the GPL, please go to:
 * http://www.gnu.org/copyleft/gpl.html
 }}} */

#ifndef _SYSLOG_STATE_H
#define _SYSLOG_STATE_H

#define SYSLOG_RETRANSMIT_TIMEOUT 5
#define SYSLOG_RETRANSMIT_COUNTER 5

#include <avr/pgmspace.h>

struct syslog_connection_state_t {
    struct {
        uint8_t transmit_state:1;
        uint8_t retransmit_timeout:7;
    };
    uint8_t retransmit_counter;
    uint8_t state;
    union {
        struct {
            uint8_t sensor;
            uint8_t sensor_state;
        };
        PGM_P str;
    };
};

#endif