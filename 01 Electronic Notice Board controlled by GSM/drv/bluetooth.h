


#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#define BT_ROBOT_STOP "STP"

#define BT_ROBOT_MOVE_FORWARD "F"
#define	BT_ROBOT_MOVE_BACKWORD "B"
#define	BT_ROBOT_TURN_LEFT "L"
#define	BT_ROBOT_TURN_RIGHT "R"

#define	BT_ROBOT_PICK_OBJECT "PO"
#define	BT_ROBOT_RELEASE_OBJECT "RO"

#define	BT_ROBOT_MOVE_ARM_UP "AU"
#define	BT_ROBOT_MOVE_ARM_DOWN "AD"


void init_Bluetooth(void);
void scan_BTData(void);
char bt_DataCompare(char *bt_db);

#endif