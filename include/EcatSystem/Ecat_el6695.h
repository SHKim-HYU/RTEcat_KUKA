/*
 * Ecat_EL6695.h
 *
 *  Created on: 2024. 02. 13.
 *      Author: Administrator
 */

#ifndef ECATSYSTEM_ECAT_EL6695_H_
#define ECATSYSTEM_ECAT_EL6695_H_

#include "Ecat_Slave.h"
#include "PDOConfig.h"

class Ecat_EL6695 : public Slave
{
public:
public:
	Ecat_EL6695() : Slave(EL6695_VendorID, EL6695_ProductCode) {}
    virtual ~Ecat_EL6695() {}

    /** Returns true if EL6695 has reached "operation enabled" state.
     *  The transition through the state machine is handled automatically. */
    bool initialized() const {return initialized_;}
    bool isSystemReady() const {return _systemReady;}
    
    void setServoOn()
    {
        // rx_krc_bits = rx_krc_bits | 0b00001000;
        _servoOn=true;
    }
    void setServoOff()
    {
        // rx_krc_bits = rx_krc_bits | 0b01000000;
        _servoOn=false;

    }
    bool isServoOn()
    {
        return _servoOn;
    }

    // int checkKRC()
    // {
    //     if (!_systemReady)
    //     {
    //         if((tx_krc_bits & 0b00000010) == 0b00000010) // Stopmess
    //             return STOPMESS_ON;
    //         else{                    
    //             if((tx_krc_bits & 0b00000100) == 0b00000000) // Not ready
    //                 return 
    //             else((tx_krc_bits & 0b00000100) == 0b00000100) // Ready
    //                 rx_krc_bits = 0b0000
    //         }
    //     }
    // }

    // void setKRCbits(uint32_t _bits)
    // {
    //     rx_krc_bits = _bits;
    // }

    /** Write the torque in Nm.
     *  User must first set max_torque_Nm_.
     *  Provided as a convenience to calculate target_torque_
     *  NOTE: function assumes [max_torque_ = 1000]  */
    void writeData(int32_t rx_Data)
    {
 	   rx_std_data = rx_Data;
    }
    void writeXdata(int32_t xd)
    {
        sxd_data = xd;
    }
    void writeYdata(int32_t yd)
    {
        syd_data = yd;
    }
    void writeZdata(int32_t zd)
    {
        szd_data = zd;
    }
    void writeAdata(int32_t ad)
    {
        sad_data = ad;
    }
    void writeBdata(int32_t bd)
    {
        sbd_data = bd;
    }
    void writeCdata(int32_t cd)
    {
        scd_data = cd;
    }
    void writeEdata(int32_t ed)
    {
        sed_data = ed;
    }


    /** Maximum torque in Nm,
     *  corresponding to the max current set in EL6695 Motion Studio */
    double max_torque_Nm_ = 1800;


	virtual void processData(size_t index, uint8_t* domain_address) //read and write PDO and if index is 8,
	{                                                               //check the state and change the flag of state
		// DATA READ WRITE
		switch(index)
		{
		//RxPDO: RSI
        case 0:
            EC_WRITE_S32(domain_address, sxd_data);
            break;
        case 1:
            EC_WRITE_S32(domain_address, syd_data);
            break;
        case 2:
            EC_WRITE_S32(domain_address, szd_data);
            break;
        case 3:
            EC_WRITE_S32(domain_address, sad_data);
            break;
        case 4:
            EC_WRITE_S32(domain_address, sbd_data);
            break;
        case 5:
            EC_WRITE_S32(domain_address, scd_data);
            break;
        case 6:
            EC_WRITE_S32(domain_address, sed_data);
            break;
        case 7:
        case 8:
        case 9:
		case 10:
		case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
            EC_WRITE_S32(domain_address, rx_std_data);
            break;
        //RxPDO: KRC
        case 32:
            EC_WRITE_S32(domain_address, rx_krc_bits);
            break;
        case 33:
            EC_WRITE_S32(domain_address, rx_std_data);
            break;
        case 34:
            EC_WRITE_S32(domain_address, rx_std_data);
            break;
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        // FT-Sensor
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
            EC_WRITE_S32(domain_address, rx_std_data);
            break;

        // TxPDO
        case 64:
            sx_data = EC_READ_S32(domain_address);
            break;
        case 65:
            sy_data = EC_READ_S32(domain_address);
            break;
        case 66:
            sz_data = EC_READ_S32(domain_address);
            break;
        case 67:
            sa_data = EC_READ_S32(domain_address);
            break;
        case 68:
            sb_data = EC_READ_S32(domain_address);
            break;
		case 69:
            sc_data = EC_READ_S32(domain_address);
            break;
        case 70:
            se_data = EC_READ_S32(domain_address);
            break;
        case 71:
            sq1_data = EC_READ_S32(domain_address);
            break;
		case 72:
            sq2_data = EC_READ_S32(domain_address);
            break;
		case 73:
            sq3_data = EC_READ_S32(domain_address);
            break;
        case 74:
            sq4_data = EC_READ_S32(domain_address);
            break;
        case 75:
            sq5_data = EC_READ_S32(domain_address);
            break;
        case 76:
            sq6_data = EC_READ_S32(domain_address);
            break;
        case 77:
            sT1_data = EC_READ_S32(domain_address);
            break;
		case 78:
            sT2_data = EC_READ_S32(domain_address);
            break;
		case 79:
            sT3_data = EC_READ_S32(domain_address);
            break;
        case 80:
            sT4_data = EC_READ_S32(domain_address);
            break;
        case 81:
            sT5_data = EC_READ_S32(domain_address);
            break;
        case 82:
            sT6_data = EC_READ_S32(domain_address);
            break;
        case 83:
            sTe_data = EC_READ_S32(domain_address);
            break;
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 95:
            tx_std_data = EC_READ_S32(domain_address);
            break;
        case 96:
        case 97:
        case 98:
            tx_std_data = EC_READ_S32(domain_address);
            break;
        case 99:
            uv1_data = EC_READ_S32(domain_address);
            break;
        case 100:
            uv2_data = EC_READ_S32(domain_address);
            break;
        case 101:
            uv3_data = EC_READ_S32(domain_address);
            break;
        case 102:
            uv4_data = EC_READ_S32(domain_address);
            break;
        case 103:
            uv5_data = EC_READ_S32(domain_address);
            break;
        case 104:
            uv6_data = EC_READ_S32(domain_address);
            break;
        case 105:
            uve_data = EC_READ_S32(domain_address);
            break;
        case 106:
        case 107:
        case 108:
        case 109:
        case 110:
        case 111:
        case 112:
        case 113:
        case 114:
        case 115:
        // FT-Sensor
        case 116:
        case 117:
        case 118:
        case 119:
        case 120:
        case 121:
        case 122:
        case 123:
        case 124:
        case 125:
        case 126:
        case 127:
            tx_std_data = EC_READ_S32(domain_address);
            break;
        

		default:
			std::cout << "WARNING. EL6695 pdo index out of range." << std::endl;
		}
    }

    virtual const ec_sync_info_t* syncs() { return &EL6695_syncs[0]; }

    virtual size_t syncSize() {
        return sizeof(EL6695_syncs)/sizeof(ec_sync_info_t);
    }

    virtual const ec_pdo_entry_info_t* channels() {
        return EL6695_pdo_entries;
    }

    virtual void domains(DomainMap& domains) const {
        domains = domains_;
    }

    int32_t rx_std_data                = 0;        // write
    uint16_t rx_std_2byte                = 0;        // write

    uint32_t rx_krc_bits = 1;

    int32_t sxd_data, syd_data, szd_data = 0;
    int32_t sad_data, sbd_data, scd_data, sed_data = 0;

    uint32_t tx_std_data                = 0;        // read
    uint32_t tx_krc_bits = 0;

    uint16_t tx_std_2byte = 0;
    int32_t sx_data=0, sy_data=0, sz_data = 0;
    int32_t sa_data=0, sb_data=0, sc_data=0, se_data = 0;
    int32_t sq1_data=0, sq2_data=0, sq3_data=0, sq4_data=0, sq5_data=0, sq6_data=0;
    int32_t sT1_data=0, sT2_data=0, sT3_data=0, sT4_data=0, sT5_data=0, sT6_data=0, sTe_data=0;
    uint32_t uv1_data=0, uv2_data=0, uv3_data=0, uv4_data=0, uv5_data=0, uv6_data=0, uve_data;
    int32_t sFx_data=0, sFy_data=0, sFz_data=0, sTx_data=0, sTy_data=0, sTz_data=0;

private:

    uint32_t digital_output_            = 0; // write
    uint32_t digital_input_             = 0; // read (must be enabled in EL6695 Motion Studio)

    DomainMap domains_ = {
    	{0, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,
            30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,
            60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,
            90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,
            120,121,122,123,124,125,126,127
        }}
    };

    enum KUKA_KRC_MODE
    {
        STOPMESS_ON = 0,
        STOPMESS_OFF = 1,
        PERI_RDY_ON = 2,
        PERI_RDY_OFF = 3,
        PRO_ACT_ON = 4,
        PRO_ACT_OFF = 5

    };

//========================================================
// EL6695 SPECIFIC
//========================================================

    bool initialized_ = false;
    bool _systemReady = true;
    bool _servoOn = false;



};

#endif /* ECATSYSTEM_ECAT_EL6695_H_ */
