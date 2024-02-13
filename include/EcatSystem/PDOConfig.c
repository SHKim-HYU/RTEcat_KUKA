#include "PDOConfig.h"

// Index, Subindex, DataType
ec_pdo_entry_info_t iServo_pdo_entries[] = {
    {0x6040, 0x00, 16}, /* controlword */
    {0x607a, 0x00, 32}, /* target_position */
    {0x60ff, 0x00, 32}, /* target_velocity */
    {0x6071, 0x00, 16}, /* target_torque */
    {0x6060, 0x00, 8}, /* modes_of_operation */

    {0x6041, 0x00, 16}, /* statusword */
    {0x6064, 0x00, 32}, /* position_actual_value */
    {0x606c, 0x00, 32}, /* velocity_actual_value */
    {0x6077, 0x00, 16}, /* torque_actual_value */
    {0x6061, 0x00, 8}, /* modes_of_operation_display */
};

ec_pdo_info_t iServo_pdos[] = {
    {0x1600, 5, iServo_pdo_entries + 0}, /* Drive RxPDO */
    {0x1a00, 5, iServo_pdo_entries + 5}, /* Drive TxPDO */
};

ec_sync_info_t iServo_syncs[] = {
    {0, EC_DIR_OUTPUT, 0, NULL, EC_WD_DISABLE},
    {1, EC_DIR_INPUT, 0, NULL, EC_WD_DISABLE},
    {2, EC_DIR_OUTPUT, 1, iServo_pdos + 0, EC_WD_ENABLE},
    {3, EC_DIR_INPUT, 1, iServo_pdos + 1, EC_WD_DISABLE},
    {0xff}
};

// Index, Subindex, DataType
ec_pdo_entry_info_t Elmo_pdo_entries[] = {
    {0x607a, 0x00, 32}, 	/* Target position */
    {0x60ff, 0x00, 32}, 	/* Target velocity */
    {0x6071, 0x00, 16}, 	/* Target torque */
    {0x6072, 0x00, 16}, 	/* Maximal torque */
    {0x6040, 0x00, 16}, 	/* Controlword */
    {0x6060, 0x00, 8}, 		/* Modes of operation */
    {0x6064, 0x00, 32}, 	/* Position actual value */
    {0x6077, 0x00, 16}, 	/* Torque value */
    {0x6041, 0x00, 16}, 	/* Statusword */
    {0x6061, 0x00, 8}, 		/* Modes of operation display */
	{0x6069, 0x00, 32},		/* Velocity actual value*/
};


ec_pdo_info_t Elmo_pdos[] = {
    {0x1605, 6, Elmo_pdo_entries + 0}, /* RPDO6 Mapping */
    {0x1a02, 4, Elmo_pdo_entries + 6}, /* TPDO3 Mapping */
	{0x1A0f, 1, Elmo_pdo_entries + 10},
};


ec_sync_info_t Elmo_syncs[5] = { 
    {0, EC_DIR_OUTPUT, 	0, NULL, EC_WD_DISABLE},
    {1, EC_DIR_INPUT, 	0, NULL, EC_WD_DISABLE},
    {2, EC_DIR_OUTPUT, 	1, Elmo_pdos + 0, EC_WD_ENABLE},
	{3, EC_DIR_INPUT, 	2, Elmo_pdos + 1, EC_WD_DISABLE},
    {0xff}
};

// Index, Subindex, DataType
ec_pdo_entry_info_t EL6695_pdo_entries[] = {
    // RxPDO: Write (256 Byte)
    // 1~128: RSI, 129~208: KRC, 209~256: FT-Sensor
    // RSI (1~128)
    {0x6010, 0x01, 32}, /* Write X data / Write Joint1 Position data [deg] */ // It deepends on Control mode
    {0x6010, 0x02, 32}, /* Write Y data / Write Joint2 Position data [deg] */
    {0x6010, 0x03, 32}, /* Write Z data / Write Joint3 Position data [deg] */
    {0x6010, 0x04, 32}, /* Write A data (Roll) / Write Joint4 Position data [deg] */
    {0x6010, 0x05, 32}, /* Write B data (Pitch) / Write Joint5 Position data [deg] */
    {0x6010, 0x06, 32}, /* Write C data (Yaw) / Write Joint6 Position data [deg] */
    {0x6010, 0x07, 32}, /* Write E data (External Joint) */
    {0x6010, 0x08, 32}, /* Std. Input DWORD 8 */
    {0x6010, 0x09, 32}, /* Std. Input DWORD 9 */
    {0x6010, 0x0a, 32}, /* Std. Input DWORD 10 */
    {0x6010, 0x0b, 32}, /* Std. Input DWORD 11 */
    {0x6010, 0x0c, 32}, /* Std. Input DWORD 12 */
    {0x6010, 0x0d, 32}, /* Std. Input DWORD 13 */
    {0x6010, 0x0e, 32}, /* Std. Input DWORD 14 */
    {0x6010, 0x0f, 32}, /* Std. Input DWORD 15 */
    {0x6010, 0x10, 32}, /* Std. Input DWORD 16 */
    {0x6010, 0x11, 32}, /* Std. Input DWORD 17 */
    {0x6010, 0x12, 32}, /* Std. Input DWORD 18 */
    {0x6010, 0x13, 32}, /* Std. Input DWORD 19 */
    {0x6010, 0x14, 32}, /* Std. Input DWORD 20 */
    {0x6010, 0x15, 32}, /* Std. Input DWORD 21 */
    {0x6010, 0x16, 32}, /* Std. Input DWORD 22 */
    {0x6010, 0x17, 32}, /* Std. Input DWORD 23 */
    {0x6010, 0x18, 32}, /* Std. Input DWORD 24 */
    {0x6010, 0x19, 32}, /* Std. Input DWORD 25 */
    {0x6010, 0x1a, 32}, /* Std. Input DWORD 26 */
    {0x6010, 0x1b, 32}, /* Std. Input DWORD 27 */
    {0x6010, 0x1c, 32}, /* Std. Input DWORD 28 */
    {0x6010, 0x1d, 32}, /* Std. Input DWORD 29 */
    {0x6010, 0x1e, 32}, /* Std. Input DWORD 30 */
    {0x6010, 0x1f, 32}, /* Std. Input DWORD 31 */
    {0x6010, 0x20, 32}, /* Std. Input DWORD 32 */
    // KRC (129~208)
    {0x6010, 0x21, 32}, /* EXT command bits */
    {0x6010, 0x22, 32}, /* Di Speed bits */
    {0x6010, 0x23, 32}, /* Di Command bits (reserved) */
    {0x6010, 0x24, 32}, /* Std. Input DWORD 36 */
    {0x6010, 0x25, 32}, /* Std. Input DWORD 37 */
    {0x6010, 0x26, 32}, /* Std. Input DWORD 38 */
    {0x6010, 0x27, 32}, /* Std. Input DWORD 39 */
    {0x6010, 0x28, 32}, /* Std. Input DWORD 40 */
    {0x6010, 0x29, 32}, /* Std. Input DWORD 41 */
    {0x6010, 0x2a, 32}, /* Std. Input DWORD 42 */
    {0x6010, 0x2b, 32}, /* Std. Input DWORD 43 */
    {0x6010, 0x2c, 32}, /* Std. Input DWORD 44 */
    {0x6010, 0x2d, 32}, /* Std. Input DWORD 45 */
    {0x6010, 0x2e, 32}, /* Std. Input DWORD 46 */
    {0x6010, 0x2f, 32}, /* Std. Input DWORD 47 */
    {0x6010, 0x30, 32}, /* Std. Input DWORD 48 */
    {0x6010, 0x31, 32}, /* Std. Input DWORD 49 */
    {0x6010, 0x32, 32}, /* Std. Input DWORD 50 */
    {0x6010, 0x33, 32}, /* Std. Input DWORD 51 */
    {0x6010, 0x34, 32}, /* Std. Input DWORD 52 */
    // FT-Sensor (209~256)
    {0x6010, 0x35, 32}, /* Std. Input DWORD 53 */
    {0x6010, 0x36, 32}, /* Std. Input DWORD 54 */
    {0x6010, 0x37, 32}, /* Std. Input DWORD 55 */
    {0x6010, 0x38, 32}, /* Std. Input DWORD 56 */
    {0x6010, 0x39, 32}, /* Std. Input DWORD 57 */
    {0x6010, 0x3a, 32}, /* Std. Input DWORD 58 */
    {0x6010, 0x3b, 32}, /* Std. Input DWORD 59 */
    {0x6010, 0x3c, 32}, /* Std. Input DWORD 60 */
    {0x6010, 0x3d, 32}, /* Std. Input DWORD 61 */
    {0x6010, 0x3e, 32}, /* Std. Input DWORD 62 */
    {0x6010, 0x3f, 32}, /* Std. Input DWORD 63 */
    {0x6010, 0x40, 32}, /* Std. Input DWORD 64 */

    // TxPDO: Read
    // 0~127: RSI, 128~199: KRC, 200~255: FT-Sensor
    {0x7010, 0x01, 32}, /* Read X data */
    {0x7010, 0x02, 32}, /* Read Y data */
    {0x7010, 0x03, 32}, /* Read Z data */
    {0x7010, 0x04, 32}, /* Read A data (Roll) */
    {0x7010, 0x05, 32}, /* Read B data (Pitch) */
    {0x7010, 0x06, 32}, /* Read C data (Yaw) */
    {0x7010, 0x07, 32}, /* Read E data (External Joint) */
    {0x7010, 0x08, 32}, /* Read Joint1 Position data [deg] */
    {0x7010, 0x09, 32}, /* Read Joint2 Position data [deg] */
    {0x7010, 0x0a, 32}, /* Read Joint3 Position data [deg] */
    {0x7010, 0x0b, 32}, /* Read Joint4 Position data [deg] */
    {0x7010, 0x0c, 32}, /* Read Joint5 Position data [deg] */
    {0x7010, 0x0d, 32}, /* Read Joint6 Position data [deg] */
    {0x7010, 0x0e, 32}, /* Read Joint1 Torque data [Nm] */
    {0x7010, 0x0f, 32}, /* Read Joint2 Torque data [Nm] */
    {0x7010, 0x10, 32}, /* Read Joint3 Torque data [Nm] */
    {0x7010, 0x11, 32}, /* Read Joint4 Torque data [Nm] */
    {0x7010, 0x12, 32}, /* Read Joint5 Torque data [Nm] */
    {0x7010, 0x13, 32}, /* Read Joint6 Torque data [Nm] */
    {0x7010, 0x14, 32}, /* Read External Joint Torque data [Nm] */
    {0x7010, 0x15, 32}, /* Std. Output DWORD 21 */
    {0x7010, 0x16, 32}, /* Std. Output DWORD 22 */
    {0x7010, 0x17, 32}, /* Std. Output DWORD 23 */
    {0x7010, 0x18, 32}, /* Std. Output DWORD 24 */
    {0x7010, 0x19, 32}, /* Std. Output DWORD 25 */
    {0x7010, 0x1a, 32}, /* Std. Output DWORD 26 */
    {0x7010, 0x1b, 32}, /* Std. Output DWORD 27 */
    {0x7010, 0x1c, 32}, /* Std. Output DWORD 28 */
    {0x7010, 0x1d, 32}, /* Std. Output DWORD 29 */
    {0x7010, 0x1e, 32}, /* Std. Output DWORD 30 */
    {0x7010, 0x1f, 32}, /* Std. Output DWORD 31 */
    {0x7010, 0x20, 32}, /* Std. Output DWORD 32 */
    // KRC (129~208)
    {0x7010, 0x21, 32}, /* EXT command bits */
    {0x7010, 0x22, 32}, /* Di Speed bits */
    {0x7010, 0x23, 32}, /* Di Command bits (reserved) */
    {0x7010, 0x24, 32}, /* Read Joint1 Velocity [100.00%] */
    {0x7010, 0x25, 32}, /* Read Joint2 Velocity [100.00%] */
    {0x7010, 0x26, 32}, /* Read Joint3 Velocity [100.00%] */
    {0x7010, 0x27, 32}, /* Read Joint4 Velocity [100.00%] */
    {0x7010, 0x28, 32}, /* Read Joint5 Velocity [100.00%] */
    {0x7010, 0x29, 32}, /* Read Joint6 Velocity [100.00%] */
    {0x7010, 0x2a, 32}, /* Read External Joint Velocity [100.00%] */
    {0x7010, 0x2b, 32}, /* Std. Output DWORD 43 */
    {0x7010, 0x2c, 32}, /* Std. Output DWORD 44 */
    {0x7010, 0x2d, 32}, /* Std. Output DWORD 45 */
    {0x7010, 0x2e, 32}, /* Std. Output DWORD 46 */
    {0x7010, 0x2f, 32}, /* Std. Output DWORD 47 */
    {0x7010, 0x30, 32}, /* Std. Output DWORD 48 */
    {0x7010, 0x31, 32}, /* Std. Output DWORD 49 */
    {0x7010, 0x32, 32}, /* Std. Output DWORD 50 */
    {0x7010, 0x33, 32}, /* Std. Output DWORD 51 */
    {0x7010, 0x34, 32}, /* Std. Output DWORD 52 */
    // FT-Sensor (209~256)
    {0x7010, 0x35, 32}, /* Std. Output DWORD 53 */
    {0x7010, 0x36, 32}, /* Std. Output DWORD 54 */
    {0x7010, 0x37, 32}, /* Std. Output DWORD 55 */
    {0x7010, 0x38, 32}, /* Std. Output DWORD 56 */
    {0x7010, 0x39, 32}, /* Std. Output DWORD 57 */
    {0x7010, 0x3a, 32}, /* Std. Output DWORD 58 */
    {0x7010, 0x3b, 32}, /* Std. Output DWORD 59 */
    {0x7010, 0x3c, 32}, /* Std. Output DWORD 60 */
    {0x7010, 0x3d, 32}, /* Std. Output DWORD 61 */
    {0x7010, 0x3e, 32}, /* Std. Output DWORD 62 */
    {0x7010, 0x3f, 32}, /* Std. Output DWORD 63 */
    {0x7010, 0x40, 32}, /* Std. Output DWORD 64 */
};

ec_pdo_info_t EL6695_pdos[] = {
    {0x1a16, 64, EL6695_pdo_entries + 0}, /* Std. RxPDO-Map */
    {0x1616, 64, EL6695_pdo_entries + 64}, /* Std. TxPDO-Map */
};

ec_sync_info_t EL6695_syncs[] = {
    {0, EC_DIR_OUTPUT, 0, NULL, EC_WD_DISABLE},
    {1, EC_DIR_INPUT, 0, NULL, EC_WD_DISABLE},
    {2, EC_DIR_OUTPUT, 1, EL6695_pdos + 0, EC_WD_ENABLE},
    {3, EC_DIR_INPUT, 1, EL6695_pdos + 1, EC_WD_DISABLE},
    {0xff}
};
