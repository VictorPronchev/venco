#include <Wire.h>
#include "SPI.h"
#include "font.h"
#include "lcd8x8rgb.h"

#define MPU9150_AUX_VDDIO          0x01   // R/W
#define MPU9150_SMPLRT_DIV         0x19   // R/W
#define MPU9150_CONFIG             0x1A   // R/W
#define MPU9150_GYRO_CONFIG        0x1B   // R/W
#define MPU9150_ACCEL_CONFIG       0x1C   // R/W
#define MPU9150_FF_THR             0x1D   // R/W
#define MPU9150_FF_DUR             0x1E   // R/W
#define MPU9150_MOT_THR            0x1F   // R/W
#define MPU9150_MOT_DUR            0x20   // R/W
#define MPU9150_ZRMOT_THR          0x21   // R/W
#define MPU9150_ZRMOT_DUR          0x22   // R/W
#define MPU9150_FIFO_EN            0x23   // R/W
#define MPU9150_I2C_MST_CTRL       0x24   // R/W
#define MPU9150_I2C_SLV0_ADDR      0x25   // R/W
#define MPU9150_I2C_SLV0_REG       0x26   // R/W
#define MPU9150_I2C_SLV0_CTRL      0x27   // R/W
#define MPU9150_I2C_SLV1_ADDR      0x28   // R/W
#define MPU9150_I2C_SLV1_REG       0x29   // R/W
#define MPU9150_I2C_SLV1_CTRL      0x2A   // R/W
#define MPU9150_I2C_SLV2_ADDR      0x2B   // R/W
#define MPU9150_I2C_SLV2_REG       0x2C   // R/W
#define MPU9150_I2C_SLV2_CTRL      0x2D   // R/W
#define MPU9150_I2C_SLV3_ADDR      0x2E   // R/W
#define MPU9150_I2C_SLV3_REG       0x2F   // R/W
#define MPU9150_I2C_SLV3_CTRL      0x30   // R/W
#define MPU9150_I2C_SLV4_ADDR      0x31   // R/W
#define MPU9150_I2C_SLV4_REG       0x32   // R/W
#define MPU9150_I2C_SLV4_DO        0x33   // R/W
#define MPU9150_I2C_SLV4_CTRL      0x34   // R/W
#define MPU9150_I2C_SLV4_DI        0x35   // R  
#define MPU9150_I2C_MST_STATUS     0x36   // R
#define MPU9150_INT_PIN_CFG        0x37   // R/W
#define MPU9150_INT_ENABLE         0x38   // R/W
#define MPU9150_INT_STATUS         0x3A   // R  
#define MPU9150_ACCEL_XOUT_H       0x3B   // R  
#define MPU9150_ACCEL_XOUT_L       0x3C   // R  
#define MPU9150_ACCEL_YOUT_H       0x3D   // R  
#define MPU9150_ACCEL_YOUT_L       0x3E   // R  
#define MPU9150_ACCEL_ZOUT_H       0x3F   // R  
#define MPU9150_ACCEL_ZOUT_L       0x40   // R  
#define MPU9150_TEMP_OUT_H         0x41   // R  
#define MPU9150_TEMP_OUT_L         0x42   // R  
#define MPU9150_GYRO_XOUT_H        0x43   // R  
#define MPU9150_GYRO_XOUT_L        0x44   // R  
#define MPU9150_GYRO_YOUT_H        0x45   // R  
#define MPU9150_GYRO_YOUT_L        0x46   // R  
#define MPU9150_GYRO_ZOUT_H        0x47   // R  
#define MPU9150_GYRO_ZOUT_L        0x48   // R  
#define MPU9150_EXT_SENS_DATA_00   0x49   // R  
#define MPU9150_EXT_SENS_DATA_01   0x4A   // R  
#define MPU9150_EXT_SENS_DATA_02   0x4B   // R  
#define MPU9150_EXT_SENS_DATA_03   0x4C   // R  
#define MPU9150_EXT_SENS_DATA_04   0x4D   // R  
#define MPU9150_EXT_SENS_DATA_05   0x4E   // R  
#define MPU9150_EXT_SENS_DATA_06   0x4F   // R  
#define MPU9150_EXT_SENS_DATA_07   0x50   // R  
#define MPU9150_EXT_SENS_DATA_08   0x51   // R  
#define MPU9150_EXT_SENS_DATA_09   0x52   // R  
#define MPU9150_EXT_SENS_DATA_10   0x53   // R  
#define MPU9150_EXT_SENS_DATA_11   0x54   // R  
#define MPU9150_EXT_SENS_DATA_12   0x55   // R  
#define MPU9150_EXT_SENS_DATA_13   0x56   // R  
#define MPU9150_EXT_SENS_DATA_14   0x57   // R  
#define MPU9150_EXT_SENS_DATA_15   0x58   // R  
#define MPU9150_EXT_SENS_DATA_16   0x59   // R  
#define MPU9150_EXT_SENS_DATA_17   0x5A   // R  
#define MPU9150_EXT_SENS_DATA_18   0x5B   // R  
#define MPU9150_EXT_SENS_DATA_19   0x5C   // R  
#define MPU9150_EXT_SENS_DATA_20   0x5D   // R  
#define MPU9150_EXT_SENS_DATA_21   0x5E   // R  
#define MPU9150_EXT_SENS_DATA_22   0x5F   // R  
#define MPU9150_EXT_SENS_DATA_23   0x60   // R  
#define MPU9150_MOT_DETECT_STATUS  0x61   // R  
#define MPU9150_I2C_SLV0_DO        0x63   // R/W
#define MPU9150_I2C_SLV1_DO        0x64   // R/W
#define MPU9150_I2C_SLV2_DO        0x65   // R/W
#define MPU9150_I2C_SLV3_DO        0x66   // R/W
#define MPU9150_I2C_MST_DELAY_CTRL 0x67   // R/W
#define MPU9150_SIGNAL_PATH_RESET  0x68   // R/W
#define MPU9150_MOT_DETECT_CTRL    0x69   // R/W
#define MPU9150_USER_CTRL          0x6A   // R/W
#define MPU9150_PWR_MGMT_1         0x6B   // R/W
#define MPU9150_PWR_MGMT_2         0x6C   // R/W
#define MPU9150_FIFO_COUNTH        0x72   // R/W
#define MPU9150_FIFO_COUNTL        0x73   // R/W
#define MPU9150_FIFO_R_W           0x74   // R/W
#define MPU9150_WHO_AM_I           0x75   // R


// Defines for the bits, to be able to change 
// between bit number and binary definition.
// By using the bit number, programming the sensor 
// is like programming the AVR microcontroller.
// But instead of using "(1<<X)", or "_BV(X)", 
// the Arduino "bit(X)" is used.
#define MPU9150_D0 0
#define MPU9150_D1 1
#define MPU9150_D2 2
#define MPU9150_D3 3
#define MPU9150_D4 4
#define MPU9150_D5 5
#define MPU9150_D6 6
#define MPU9150_D7 7

// AUX_VDDIO Register
#define MPU9150_AUX_VDDIO MPU9150_D7  // I2C high: 1=VDD, 0=VLOGIC

// CONFIG Register
// DLPF is Digital Low Pass Filter for both gyro and accelerometers.
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_DLPF_CFG0     MPU9150_D0
#define MPU9150_DLPF_CFG1     MPU9150_D1
#define MPU9150_DLPF_CFG2     MPU9150_D2
#define MPU9150_EXT_SYNC_SET0 MPU9150_D3
#define MPU9150_EXT_SYNC_SET1 MPU9150_D4
#define MPU9150_EXT_SYNC_SET2 MPU9150_D5

// Combined definitions for the EXT_SYNC_SET values
#define MPU9150_EXT_SYNC_SET_0 (0)
#define MPU9150_EXT_SYNC_SET_1 (bit(MPU9150_EXT_SYNC_SET0))
#define MPU9150_EXT_SYNC_SET_2 (bit(MPU9150_EXT_SYNC_SET1))
#define MPU9150_EXT_SYNC_SET_3 (bit(MPU9150_EXT_SYNC_SET1)|bit(MPU9150_EXT_SYNC_SET0))
#define MPU9150_EXT_SYNC_SET_4 (bit(MPU9150_EXT_SYNC_SET2))
#define MPU9150_EXT_SYNC_SET_5 (bit(MPU9150_EXT_SYNC_SET2)|bit(MPU9150_EXT_SYNC_SET0))
#define MPU9150_EXT_SYNC_SET_6 (bit(MPU9150_EXT_SYNC_SET2)|bit(MPU9150_EXT_SYNC_SET1))
#define MPU9150_EXT_SYNC_SET_7 (bit(MPU9150_EXT_SYNC_SET2)|bit(MPU9150_EXT_SYNC_SET1)|bit(MPU9150_EXT_SYNC_SET0))

// Alternative names for the combined definitions.
#define MPU9150_EXT_SYNC_DISABLED     MPU9150_EXT_SYNC_SET_0
#define MPU9150_EXT_SYNC_TEMP_OUT_L   MPU9150_EXT_SYNC_SET_1
#define MPU9150_EXT_SYNC_GYRO_XOUT_L  MPU9150_EXT_SYNC_SET_2
#define MPU9150_EXT_SYNC_GYRO_YOUT_L  MPU9150_EXT_SYNC_SET_3
#define MPU9150_EXT_SYNC_GYRO_ZOUT_L  MPU9150_EXT_SYNC_SET_4
#define MPU9150_EXT_SYNC_ACCEL_XOUT_L MPU9150_EXT_SYNC_SET_5
#define MPU9150_EXT_SYNC_ACCEL_YOUT_L MPU9150_EXT_SYNC_SET_6
#define MPU9150_EXT_SYNC_ACCEL_ZOUT_L MPU9150_EXT_SYNC_SET_7

// Combined definitions for the DLPF_CFG values
#define MPU9150_DLPF_CFG_0 (0)
#define MPU9150_DLPF_CFG_1 (bit(MPU9150_DLPF_CFG0))
#define MPU9150_DLPF_CFG_2 (bit(MPU9150_DLPF_CFG1))
#define MPU9150_DLPF_CFG_3 (bit(MPU9150_DLPF_CFG1)|bit(MPU9150_DLPF_CFG0))
#define MPU9150_DLPF_CFG_4 (bit(MPU9150_DLPF_CFG2))
#define MPU9150_DLPF_CFG_5 (bit(MPU9150_DLPF_CFG2)|bit(MPU9150_DLPF_CFG0))
#define MPU9150_DLPF_CFG_6 (bit(MPU9150_DLPF_CFG2)|bit(MPU9150_DLPF_CFG1))
#define MPU9150_DLPF_CFG_7 (bit(MPU9150_DLPF_CFG2)|bit(MPU9150_DLPF_CFG1)|bit(MPU9150_DLPF_CFG0))

// Alternative names for the combined definitions
// This name uses the bandwidth (Hz) for the accelometer,
// for the gyro the bandwidth is almost the same.
#define MPU9150_DLPF_260HZ    MPU9150_DLPF_CFG_0
#define MPU9150_DLPF_184HZ    MPU9150_DLPF_CFG_1
#define MPU9150_DLPF_94HZ     MPU9150_DLPF_CFG_2
#define MPU9150_DLPF_44HZ     MPU9150_DLPF_CFG_3
#define MPU9150_DLPF_21HZ     MPU9150_DLPF_CFG_4
#define MPU9150_DLPF_10HZ     MPU9150_DLPF_CFG_5
#define MPU9150_DLPF_5HZ      MPU9150_DLPF_CFG_6
#define MPU9150_DLPF_RESERVED MPU9150_DLPF_CFG_7

// GYRO_CONFIG Register
// The XG_ST, YG_ST, ZG_ST are bits for selftest.
// The FS_SEL sets the range for the gyro.
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_FS_SEL0 MPU9150_D3
#define MPU9150_FS_SEL1 MPU9150_D4
#define MPU9150_ZG_ST   MPU9150_D5
#define MPU9150_YG_ST   MPU9150_D6
#define MPU9150_XG_ST   MPU9150_D7

// Combined definitions for the FS_SEL values
#define MPU9150_FS_SEL_0 (0)
#define MPU9150_FS_SEL_1 (bit(MPU9150_FS_SEL0))
#define MPU9150_FS_SEL_2 (bit(MPU9150_FS_SEL1))
#define MPU9150_FS_SEL_3 (bit(MPU9150_FS_SEL1)|bit(MPU9150_FS_SEL0))

// Alternative names for the combined definitions
// The name uses the range in degrees per second.
#define MPU9150_FS_SEL_250  MPU9150_FS_SEL_0
#define MPU9150_FS_SEL_500  MPU9150_FS_SEL_1
#define MPU9150_FS_SEL_1000 MPU9150_FS_SEL_2
#define MPU9150_FS_SEL_2000 MPU9150_FS_SEL_3

// ACCEL_CONFIG Register
// The XA_ST, YA_ST, ZA_ST are bits for selftest.
// The AFS_SEL sets the range for the accelerometer.
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_ACCEL_HPF0 MPU9150_D0
#define MPU9150_ACCEL_HPF1 MPU9150_D1
#define MPU9150_ACCEL_HPF2 MPU9150_D2
#define MPU9150_AFS_SEL0   MPU9150_D3
#define MPU9150_AFS_SEL1   MPU9150_D4
#define MPU9150_ZA_ST      MPU9150_D5
#define MPU9150_YA_ST      MPU9150_D6
#define MPU9150_XA_ST      MPU9150_D7

// Combined definitions for the ACCEL_HPF values
#define MPU9150_ACCEL_HPF_0 (0)
#define MPU9150_ACCEL_HPF_1 (bit(MPU9150_ACCEL_HPF0))
#define MPU9150_ACCEL_HPF_2 (bit(MPU9150_ACCEL_HPF1))
#define MPU9150_ACCEL_HPF_3 (bit(MPU9150_ACCEL_HPF1)|bit(MPU9150_ACCEL_HPF0))
#define MPU9150_ACCEL_HPF_4 (bit(MPU9150_ACCEL_HPF2))
#define MPU9150_ACCEL_HPF_7 (bit(MPU9150_ACCEL_HPF2)|bit(MPU9150_ACCEL_HPF1)|bit(MPU9150_ACCEL_HPF0))

// Alternative names for the combined definitions
// The name uses the Cut-off frequency.
#define MPU9150_ACCEL_HPF_RESET  MPU9150_ACCEL_HPF_0
#define MPU9150_ACCEL_HPF_5HZ    MPU9150_ACCEL_HPF_1
#define MPU9150_ACCEL_HPF_2_5HZ  MPU9150_ACCEL_HPF_2
#define MPU9150_ACCEL_HPF_1_25HZ MPU9150_ACCEL_HPF_3
#define MPU9150_ACCEL_HPF_0_63HZ MPU9150_ACCEL_HPF_4
#define MPU9150_ACCEL_HPF_HOLD   MPU9150_ACCEL_HPF_7

// Combined definitions for the AFS_SEL values
#define MPU9150_AFS_SEL_0 (0)
#define MPU9150_AFS_SEL_1 (bit(MPU9150_AFS_SEL0))
#define MPU9150_AFS_SEL_2 (bit(MPU9150_AFS_SEL1))
#define MPU9150_AFS_SEL_3 (bit(MPU9150_AFS_SEL1)|bit(MPU9150_AFS_SEL0))

// Alternative names for the combined definitions
// The name uses the full scale range for the accelerometer.
#define MPU9150_AFS_SEL_2G  MPU9150_AFS_SEL_0
#define MPU9150_AFS_SEL_4G  MPU9150_AFS_SEL_1
#define MPU9150_AFS_SEL_8G  MPU9150_AFS_SEL_2
#define MPU9150_AFS_SEL_16G MPU9150_AFS_SEL_3

// FIFO_EN Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_SLV0_FIFO_EN  MPU9150_D0
#define MPU9150_SLV1_FIFO_EN  MPU9150_D1
#define MPU9150_SLV2_FIFO_EN  MPU9150_D2
#define MPU9150_ACCEL_FIFO_EN MPU9150_D3
#define MPU9150_ZG_FIFO_EN    MPU9150_D4
#define MPU9150_YG_FIFO_EN    MPU9150_D5
#define MPU9150_XG_FIFO_EN    MPU9150_D6
#define MPU9150_TEMP_FIFO_EN  MPU9150_D7

// I2C_MST_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_MST_CLK0  MPU9150_D0
#define MPU9150_I2C_MST_CLK1  MPU9150_D1
#define MPU9150_I2C_MST_CLK2  MPU9150_D2
#define MPU9150_I2C_MST_CLK3  MPU9150_D3
#define MPU9150_I2C_MST_P_NSR MPU9150_D4
#define MPU9150_SLV_3_FIFO_EN MPU9150_D5
#define MPU9150_WAIT_FOR_ES   MPU9150_D6
#define MPU9150_MULT_MST_EN   MPU9150_D7

// Combined definitions for the I2C_MST_CLK
#define MPU9150_I2C_MST_CLK_0 (0)
#define MPU9150_I2C_MST_CLK_1  (bit(MPU9150_I2C_MST_CLK0))
#define MPU9150_I2C_MST_CLK_2  (bit(MPU9150_I2C_MST_CLK1))
#define MPU9150_I2C_MST_CLK_3  (bit(MPU9150_I2C_MST_CLK1)|bit(MPU9150_I2C_MST_CLK0))
#define MPU9150_I2C_MST_CLK_4  (bit(MPU9150_I2C_MST_CLK2))
#define MPU9150_I2C_MST_CLK_5  (bit(MPU9150_I2C_MST_CLK2)|bit(MPU9150_I2C_MST_CLK0))
#define MPU9150_I2C_MST_CLK_6  (bit(MPU9150_I2C_MST_CLK2)|bit(MPU9150_I2C_MST_CLK1))
#define MPU9150_I2C_MST_CLK_7  (bit(MPU9150_I2C_MST_CLK2)|bit(MPU9150_I2C_MST_CLK1)|bit(MPU9150_I2C_MST_CLK0))
#define MPU9150_I2C_MST_CLK_8  (bit(MPU9150_I2C_MST_CLK3))
#define MPU9150_I2C_MST_CLK_9  (bit(MPU9150_I2C_MST_CLK3)|bit(MPU9150_I2C_MST_CLK0))
#define MPU9150_I2C_MST_CLK_10 (bit(MPU9150_I2C_MST_CLK3)|bit(MPU9150_I2C_MST_CLK1))
#define MPU9150_I2C_MST_CLK_11 (bit(MPU9150_I2C_MST_CLK3)|bit(MPU9150_I2C_MST_CLK1)|bit(MPU9150_I2C_MST_CLK0))
#define MPU9150_I2C_MST_CLK_12 (bit(MPU9150_I2C_MST_CLK3)|bit(MPU9150_I2C_MST_CLK2))
#define MPU9150_I2C_MST_CLK_13 (bit(MPU9150_I2C_MST_CLK3)|bit(MPU9150_I2C_MST_CLK2)|bit(MPU9150_I2C_MST_CLK0))
#define MPU9150_I2C_MST_CLK_14 (bit(MPU9150_I2C_MST_CLK3)|bit(MPU9150_I2C_MST_CLK2)|bit(MPU9150_I2C_MST_CLK1))
#define MPU9150_I2C_MST_CLK_15 (bit(MPU9150_I2C_MST_CLK3)|bit(MPU9150_I2C_MST_CLK2)|bit(MPU9150_I2C_MST_CLK1)|bit(MPU9150_I2C_MST_CLK0))

// Alternative names for the combined definitions
// The names uses I2C Master Clock Speed in kHz.
#define MPU9150_I2C_MST_CLK_348KHZ MPU9150_I2C_MST_CLK_0
#define MPU9150_I2C_MST_CLK_333KHZ MPU9150_I2C_MST_CLK_1
#define MPU9150_I2C_MST_CLK_320KHZ MPU9150_I2C_MST_CLK_2
#define MPU9150_I2C_MST_CLK_308KHZ MPU9150_I2C_MST_CLK_3
#define MPU9150_I2C_MST_CLK_296KHZ MPU9150_I2C_MST_CLK_4
#define MPU9150_I2C_MST_CLK_286KHZ MPU9150_I2C_MST_CLK_5
#define MPU9150_I2C_MST_CLK_276KHZ MPU9150_I2C_MST_CLK_6
#define MPU9150_I2C_MST_CLK_267KHZ MPU9150_I2C_MST_CLK_7
#define MPU9150_I2C_MST_CLK_258KHZ MPU9150_I2C_MST_CLK_8
#define MPU9150_I2C_MST_CLK_500KHZ MPU9150_I2C_MST_CLK_9
#define MPU9150_I2C_MST_CLK_471KHZ MPU9150_I2C_MST_CLK_10
#define MPU9150_I2C_MST_CLK_444KHZ MPU9150_I2C_MST_CLK_11
#define MPU9150_I2C_MST_CLK_421KHZ MPU9150_I2C_MST_CLK_12
#define MPU9150_I2C_MST_CLK_400KHZ MPU9150_I2C_MST_CLK_13
#define MPU9150_I2C_MST_CLK_381KHZ MPU9150_I2C_MST_CLK_14
#define MPU9150_I2C_MST_CLK_364KHZ MPU9150_I2C_MST_CLK_15

// I2C_SLV0_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV0_RW MPU9150_D7

// I2C_SLV0_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV0_LEN0    MPU9150_D0
#define MPU9150_I2C_SLV0_LEN1    MPU9150_D1
#define MPU9150_I2C_SLV0_LEN2    MPU9150_D2
#define MPU9150_I2C_SLV0_LEN3    MPU9150_D3
#define MPU9150_I2C_SLV0_GRP     MPU9150_D4
#define MPU9150_I2C_SLV0_REG_DIS MPU9150_D5
#define MPU9150_I2C_SLV0_BYTE_SW MPU9150_D6
#define MPU9150_I2C_SLV0_EN      MPU9150_D7

// A mask for the length
#define MPU9150_I2C_SLV0_LEN_MASK 0x0F

// I2C_SLV1_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV1_RW MPU9150_D7

// I2C_SLV1_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV1_LEN0    MPU9150_D0
#define MPU9150_I2C_SLV1_LEN1    MPU9150_D1
#define MPU9150_I2C_SLV1_LEN2    MPU9150_D2
#define MPU9150_I2C_SLV1_LEN3    MPU9150_D3
#define MPU9150_I2C_SLV1_GRP     MPU9150_D4
#define MPU9150_I2C_SLV1_REG_DIS MPU9150_D5
#define MPU9150_I2C_SLV1_BYTE_SW MPU9150_D6
#define MPU9150_I2C_SLV1_EN      MPU9150_D7

// A mask for the length
#define MPU9150_I2C_SLV1_LEN_MASK 0x0F

// I2C_SLV2_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV2_RW MPU9150_D7

// I2C_SLV2_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV2_LEN0    MPU9150_D0
#define MPU9150_I2C_SLV2_LEN1    MPU9150_D1
#define MPU9150_I2C_SLV2_LEN2    MPU9150_D2
#define MPU9150_I2C_SLV2_LEN3    MPU9150_D3
#define MPU9150_I2C_SLV2_GRP     MPU9150_D4
#define MPU9150_I2C_SLV2_REG_DIS MPU9150_D5
#define MPU9150_I2C_SLV2_BYTE_SW MPU9150_D6
#define MPU9150_I2C_SLV2_EN      MPU9150_D7

// A mask for the length
#define MPU9150_I2C_SLV2_LEN_MASK 0x0F

// I2C_SLV3_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV3_RW MPU9150_D7

// I2C_SLV3_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV3_LEN0    MPU9150_D0
#define MPU9150_I2C_SLV3_LEN1    MPU9150_D1
#define MPU9150_I2C_SLV3_LEN2    MPU9150_D2
#define MPU9150_I2C_SLV3_LEN3    MPU9150_D3
#define MPU9150_I2C_SLV3_GRP     MPU9150_D4
#define MPU9150_I2C_SLV3_REG_DIS MPU9150_D5
#define MPU9150_I2C_SLV3_BYTE_SW MPU9150_D6
#define MPU9150_I2C_SLV3_EN      MPU9150_D7

// A mask for the length
#define MPU9150_I2C_SLV3_LEN_MASK 0x0F

// I2C_SLV4_ADDR Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV4_RW MPU9150_D7

// I2C_SLV4_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_MST_DLY0     MPU9150_D0
#define MPU9150_I2C_MST_DLY1     MPU9150_D1
#define MPU9150_I2C_MST_DLY2     MPU9150_D2
#define MPU9150_I2C_MST_DLY3     MPU9150_D3
#define MPU9150_I2C_MST_DLY4     MPU9150_D4
#define MPU9150_I2C_SLV4_REG_DIS MPU9150_D5
#define MPU9150_I2C_SLV4_INT_EN  MPU9150_D6
#define MPU9150_I2C_SLV4_EN      MPU9150_D7

// A mask for the delay
#define MPU9150_I2C_MST_DLY_MASK 0x1F

// I2C_MST_STATUS Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV0_NACK MPU9150_D0
#define MPU9150_I2C_SLV1_NACK MPU9150_D1
#define MPU9150_I2C_SLV2_NACK MPU9150_D2
#define MPU9150_I2C_SLV3_NACK MPU9150_D3
#define MPU9150_I2C_SLV4_NACK MPU9150_D4
#define MPU9150_I2C_LOST_ARB  MPU9150_D5
#define MPU9150_I2C_SLV4_DONE MPU9150_D6
#define MPU9150_PASS_THROUGH  MPU9150_D7

// I2C_PIN_CFG Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_CLKOUT_EN       MPU9150_D0
#define MPU9150_I2C_BYPASS_EN   MPU9150_D1
#define MPU9150_FSYNC_INT_EN    MPU9150_D2
#define MPU9150_FSYNC_INT_LEVEL MPU9150_D3
#define MPU9150_INT_RD_CLEAR    MPU9150_D4
#define MPU9150_LATCH_INT_EN    MPU9150_D5
#define MPU9150_INT_OPEN        MPU9150_D6
#define MPU9150_INT_LEVEL       MPU9150_D7

// INT_ENABLE Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_DATA_RDY_EN    MPU9150_D0
#define MPU9150_I2C_MST_INT_EN MPU9150_D3
#define MPU9150_FIFO_OFLOW_EN  MPU9150_D4
#define MPU9150_ZMOT_EN        MPU9150_D5
#define MPU9150_MOT_EN         MPU9150_D6
#define MPU9150_FF_EN          MPU9150_D7

// INT_STATUS Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_DATA_RDY_INT   MPU9150_D0
#define MPU9150_I2C_MST_INT    MPU9150_D3
#define MPU9150_FIFO_OFLOW_INT MPU9150_D4
#define MPU9150_ZMOT_INT       MPU9150_D5
#define MPU9150_MOT_INT        MPU9150_D6
#define MPU9150_FF_INT         MPU9150_D7

// MOT_DETECT_STATUS Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_MOT_ZRMOT MPU9150_D0
#define MPU9150_MOT_ZPOS  MPU9150_D2
#define MPU9150_MOT_ZNEG  MPU9150_D3
#define MPU9150_MOT_YPOS  MPU9150_D4
#define MPU9150_MOT_YNEG  MPU9150_D5
#define MPU9150_MOT_XPOS  MPU9150_D6
#define MPU9150_MOT_XNEG  MPU9150_D7

// IC2_MST_DELAY_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_I2C_SLV0_DLY_EN MPU9150_D0
#define MPU9150_I2C_SLV1_DLY_EN MPU9150_D1
#define MPU9150_I2C_SLV2_DLY_EN MPU9150_D2
#define MPU9150_I2C_SLV3_DLY_EN MPU9150_D3
#define MPU9150_I2C_SLV4_DLY_EN MPU9150_D4
#define MPU9150_DELAY_ES_SHADOW MPU9150_D7

// SIGNAL_PATH_RESET Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_TEMP_RESET  MPU9150_D0
#define MPU9150_ACCEL_RESET MPU9150_D1
#define MPU9150_GYRO_RESET  MPU9150_D2

// MOT_DETECT_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_MOT_COUNT0      MPU9150_D0
#define MPU9150_MOT_COUNT1      MPU9150_D1
#define MPU9150_FF_COUNT0       MPU9150_D2
#define MPU9150_FF_COUNT1       MPU9150_D3
#define MPU9150_ACCEL_ON_DELAY0 MPU9150_D4
#define MPU9150_ACCEL_ON_DELAY1 MPU9150_D5

// Combined definitions for the MOT_COUNT
#define MPU9150_MOT_COUNT_0 (0)
#define MPU9150_MOT_COUNT_1 (bit(MPU9150_MOT_COUNT0))
#define MPU9150_MOT_COUNT_2 (bit(MPU9150_MOT_COUNT1))
#define MPU9150_MOT_COUNT_3 (bit(MPU9150_MOT_COUNT1)|bit(MPU9150_MOT_COUNT0))

// Alternative names for the combined definitions
#define MPU9150_MOT_COUNT_RESET MPU9150_MOT_COUNT_0

// Combined definitions for the FF_COUNT
#define MPU9150_FF_COUNT_0 (0)
#define MPU9150_FF_COUNT_1 (bit(MPU9150_FF_COUNT0))
#define MPU9150_FF_COUNT_2 (bit(MPU9150_FF_COUNT1))
#define MPU9150_FF_COUNT_3 (bit(MPU9150_FF_COUNT1)|bit(MPU9150_FF_COUNT0))

// Alternative names for the combined definitions
#define MPU9150_FF_COUNT_RESET MPU9150_FF_COUNT_0

// Combined definitions for the ACCEL_ON_DELAY
#define MPU9150_ACCEL_ON_DELAY_0 (0)
#define MPU9150_ACCEL_ON_DELAY_1 (bit(MPU9150_ACCEL_ON_DELAY0))
#define MPU9150_ACCEL_ON_DELAY_2 (bit(MPU9150_ACCEL_ON_DELAY1))
#define MPU9150_ACCEL_ON_DELAY_3 (bit(MPU9150_ACCEL_ON_DELAY1)|bit(MPU9150_ACCEL_ON_DELAY0))

// Alternative names for the ACCEL_ON_DELAY
#define MPU9150_ACCEL_ON_DELAY_0MS MPU9150_ACCEL_ON_DELAY_0
#define MPU9150_ACCEL_ON_DELAY_1MS MPU9150_ACCEL_ON_DELAY_1
#define MPU9150_ACCEL_ON_DELAY_2MS MPU9150_ACCEL_ON_DELAY_2
#define MPU9150_ACCEL_ON_DELAY_3MS MPU9150_ACCEL_ON_DELAY_3

// USER_CTRL Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_SIG_COND_RESET MPU9150_D0
#define MPU9150_I2C_MST_RESET  MPU9150_D1
#define MPU9150_FIFO_RESET     MPU9150_D2
#define MPU9150_I2C_IF_DIS     MPU9150_D4   // must be 0 for MPU-9150
#define MPU9150_I2C_MST_EN     MPU9150_D5
#define MPU9150_FIFO_EN        MPU9150_D6

// PWR_MGMT_1 Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_CLKSEL0      MPU9150_D0
#define MPU9150_CLKSEL1      MPU9150_D1
#define MPU9150_CLKSEL2      MPU9150_D2
#define MPU9150_TEMP_DIS     MPU9150_D3    // 1: disable temperature sensor
#define MPU9150_CYCLE        MPU9150_D5    // 1: sample and sleep
#define MPU9150_SLEEP        MPU9150_D6    // 1: sleep mode
#define MPU9150_DEVICE_RESET MPU9150_D7    // 1: reset to default values

// Combined definitions for the CLKSEL
#define MPU9150_CLKSEL_0 (0)
#define MPU9150_CLKSEL_1 (bit(MPU9150_CLKSEL0))
#define MPU9150_CLKSEL_2 (bit(MPU9150_CLKSEL1))
#define MPU9150_CLKSEL_3 (bit(MPU9150_CLKSEL1)|bit(MPU9150_CLKSEL0))
#define MPU9150_CLKSEL_4 (bit(MPU9150_CLKSEL2))
#define MPU9150_CLKSEL_5 (bit(MPU9150_CLKSEL2)|bit(MPU9150_CLKSEL0))
#define MPU9150_CLKSEL_6 (bit(MPU9150_CLKSEL2)|bit(MPU9150_CLKSEL1))
#define MPU9150_CLKSEL_7 (bit(MPU9150_CLKSEL2)|bit(MPU9150_CLKSEL1)|bit(MPU9150_CLKSEL0))

// Alternative names for the combined definitions
#define MPU9150_CLKSEL_INTERNAL    MPU9150_CLKSEL_0
#define MPU9150_CLKSEL_X           MPU9150_CLKSEL_1
#define MPU9150_CLKSEL_Y           MPU9150_CLKSEL_2
#define MPU9150_CLKSEL_Z           MPU9150_CLKSEL_3
#define MPU9150_CLKSEL_EXT_32KHZ   MPU9150_CLKSEL_4
#define MPU9150_CLKSEL_EXT_19_2MHZ MPU9150_CLKSEL_5
#define MPU9150_CLKSEL_RESERVED    MPU9150_CLKSEL_6
#define MPU9150_CLKSEL_STOP        MPU9150_CLKSEL_7

// PWR_MGMT_2 Register
// These are the names for the bits.
// Use these only with the bit() macro.
#define MPU9150_STBY_ZG       MPU9150_D0
#define MPU9150_STBY_YG       MPU9150_D1
#define MPU9150_STBY_XG       MPU9150_D2
#define MPU9150_STBY_ZA       MPU9150_D3
#define MPU9150_STBY_YA       MPU9150_D4
#define MPU9150_STBY_XA       MPU9150_D5
#define MPU9150_LP_WAKE_CTRL0 MPU9150_D6
#define MPU9150_LP_WAKE_CTRL1 MPU9150_D7

// Combined definitions for the LP_WAKE_CTRL
#define MPU9150_LP_WAKE_CTRL_0 (0)
#define MPU9150_LP_WAKE_CTRL_1 (bit(MPU9150_LP_WAKE_CTRL0))
#define MPU9150_LP_WAKE_CTRL_2 (bit(MPU9150_LP_WAKE_CTRL1))
#define MPU9150_LP_WAKE_CTRL_3 (bit(MPU9150_LP_WAKE_CTRL1)|bit(MPU9150_LP_WAKE_CTRL0))

// Alternative names for the combined definitions
// The names uses the Wake-up Frequency.
#define MPU9150_LP_WAKE_1_25HZ MPU9150_LP_WAKE_CTRL_0
#define MPU9150_LP_WAKE_2_5HZ  MPU9150_LP_WAKE_CTRL_1
#define MPU9150_LP_WAKE_5HZ    MPU9150_LP_WAKE_CTRL_2
#define MPU9150_LP_WAKE_10HZ   MPU9150_LP_WAKE_CTRL_3


// Default I2C address for the MPU-9150 is 0x68.
// But only if the AD0 pin is low.
// Some sensor boards have AD0 high, and the
// I2C address thus becomes 0x69.
#define MPU9150_I2C_ADDRESS 0x68


//Led
boolean point=1;
unsigned char l[] = "))";
unsigned char r[] = "((";
unsigned char s[] = "STOP";
unsigned char f[] = "^^";
unsigned int cntr=0;
unsigned int cntr2=31;
unsigned int cntr3=31;
unsigned int cntr4=31;
unsigned int shake=0;
unsigned int walk=0;
char step=-1;            // direction of signs

// Declaring an union for the registers and the axis values.
// The byte order does not match the byte order of 
// the compiler and AVR chip.
// The AVR chip (on the Arduino board) has the Low Byte 
// at the lower address.
// But the MPU-9150 has a different order: High Byte at
// lower address, so that has to be corrected.
// The register part "reg" is only used internally, 
// and are swapped in code.
typedef union accel_t_gyro_union
{
  struct
  {
    uint8_t x_accel_h;
    uint8_t x_accel_l;
    uint8_t y_accel_h;
    uint8_t y_accel_l;
    uint8_t z_accel_h;
    uint8_t z_accel_l;
    uint8_t t_h;
    uint8_t t_l;
    uint8_t x_gyro_h;
    uint8_t x_gyro_l;
    uint8_t y_gyro_h;
    uint8_t y_gyro_l;
    uint8_t z_gyro_h;
    uint8_t z_gyro_l;
  } reg;
  struct 
  {
    int16_t x_accel;
    int16_t y_accel;
    int16_t z_accel;
    int16_t temperature;
    int16_t x_gyro;
    int16_t y_gyro;
    int16_t z_gyro;
  } value;
};

accel_t_gyro_union accel_t_gyro;

void readGyro()
{
  int error;

  error = MPU9150_read (MPU9150_ACCEL_XOUT_H, (uint8_t *) &accel_t_gyro, sizeof(accel_t_gyro));

  uint8_t swap;
  #define SWAP(x,y) swap = x; x = y; y = swap

  SWAP (accel_t_gyro.reg.x_accel_h, accel_t_gyro.reg.x_accel_l);
  SWAP (accel_t_gyro.reg.y_accel_h, accel_t_gyro.reg.y_accel_l);
  SWAP (accel_t_gyro.reg.z_accel_h, accel_t_gyro.reg.z_accel_l);
  SWAP (accel_t_gyro.reg.t_h, accel_t_gyro.reg.t_l);
  SWAP (accel_t_gyro.reg.x_gyro_h, accel_t_gyro.reg.x_gyro_l);
  SWAP (accel_t_gyro.reg.y_gyro_h, accel_t_gyro.reg.y_gyro_l);
  SWAP (accel_t_gyro.reg.z_gyro_h, accel_t_gyro.reg.z_gyro_l);
  
  accel_t_gyro.value.x_accel = map(accel_t_gyro.value.x_accel, 0, 17000, 0, 180);
  accel_t_gyro.value.y_accel = map(accel_t_gyro.value.y_accel, 0, 17000, 0, 180);
  accel_t_gyro.value.z_accel = map(accel_t_gyro.value.z_accel, 0, 17000, 0, 180);  
  accel_t_gyro.value.x_gyro = map(accel_t_gyro.value.x_gyro, 0, 17000, 0, 180);
  accel_t_gyro.value.y_gyro = map(accel_t_gyro.value.y_gyro, 0, 17000, 0, 180);
  accel_t_gyro.value.z_gyro = map(accel_t_gyro.value.z_gyro, 0, 17000, 0, 180);  
}


void setup()
{      
  int error;
  uint8_t c;


   pinMode(8, OUTPUT);
   Serial.begin(57600);
    Serial.begin(57600);
    while (Serial) { 
    }
  //Serial.println(F("VenCo"));
  //Serial.println(F("20.12.2015"));

  // Initialize the 'Wire' class for the I2C-bus.
  Wire.begin();


  // default at power-up:
  //    Gyro at 250 degrees second
  //    Acceleration at 2g
  //    Clock source at internal 8MHz
  //    The device is in sleep mode.
  //

  error = MPU9150_read (MPU9150_WHO_AM_I, &c, 1);
  //Serial.print(F("WHO_AM_I : "));
  //Serial.print(c,HEX);
  //Serial.print(F(", error = "));
  //Serial.println(error,DEC);

  // According to the datasheet, the 'sleep' bit
  // should read a '1'.
  // That bit has to be cleared, since the sensor
  // is in sleep mode at power-up. 
  error = MPU9150_read (MPU9150_PWR_MGMT_1, &c, 1);
  //Serial.print(F("PWR_MGMT_1 : "));
  //Serial.print(c,HEX);
  //Serial.print(F(", error = "));
  //Serial.println(error,DEC);


  // Clear the 'sleep' bit to start the sensor.
  MPU9150_write_reg (MPU9150_PWR_MGMT_1, 0);
  // LED 
   SPI.setDataMode(SPI_MODE1);
   SPI.setClockDivider(SPI_CLOCK_DIV64);
   SPI.begin();

   pinMode(chipSelectPin, OUTPUT);

   vClear();
}



// --------------------------------------------------------
// MPU9150_read
//
// This is a common function to read multiple bytes 
// from an I2C device.
//
// It uses the boolean parameter for Wire.endTransMission()
// to be able to hold or release the I2C-bus. 
// This is implemented in Arduino 1.0.1.
//
// Only this function is used to read. 
// There is no function for a single byte.
//
int MPU9150_read(int start, uint8_t *buffer, int size)
{
  int i, n, error;

  Wire.beginTransmission(MPU9150_I2C_ADDRESS);
  n = Wire.write(start);
  if (n != 1)
    return (-10);

  n = Wire.endTransmission(false);    // hold the I2C-bus
  if (n != 0)
    return (n);

  // Third parameter is true: relase I2C-bus after data is read.
  Wire.requestFrom(MPU9150_I2C_ADDRESS, size, true);
  i = 0;
  while(Wire.available() && i<size)
  {
    buffer[i++]=Wire.read();
  }
  if ( i != size)
    return (-11);

  return (0);  // return : no error
}


// --------------------------------------------------------
// MPU9150_write
//
// This is a common function to write multiple bytes to an I2C device.
//
// If only a single register is written,
// use the function MPU_9150_write_reg().
//
// Parameters:
//   start : Start address, use a define for the register
//   pData : A pointer to the data to write.
//   size  : The number of bytes to write.
//
// If only a single register is written, a pointer
// to the data has to be used, and the size is
// a single byte:
//   int data = 0;        // the data to write
//   MPU9150_write (MPU9150_PWR_MGMT_1, &c, 1);
//
int MPU9150_write(int start, const uint8_t *pData, int size)
{
  int n, error;

  Wire.beginTransmission(MPU9150_I2C_ADDRESS);
  n = Wire.write(start);        // write the start address
  if (n != 1)
    return (-20);

  n = Wire.write(pData, size);  // write data bytes
  if (n != size)
    return (-21);

  error = Wire.endTransmission(true); // release the I2C-bus
  if (error != 0)
    return (error);

  return (0);         // return : no error
}

// --------------------------------------------------------
// MPU9150_write_reg
//
// An extra function to write a single register.
// It is just a wrapper around the MPU_9150_write()
// function, and it is only a convenient function
// to make it easier to write a single register.
//
int MPU9150_write_reg(int reg, uint8_t data)
{
  int error;

  error = MPU9150_write(reg, &data, 1);

  return (error);
}

struct pos
{
   short x;
   short y;
};
struct ldirections
{
   long up;
   long down;
   long left;
   long right;   
};
struct sdirections
{
   short forward;
   short backward;
   short up;
   short down;
   short left;
   short right;   
};


boolean colors[3][8][8];

pos ballspos;

ldirections ballsmovedelay;
sdirections triggerlevel;


void loop()
{
  int error;
  double dT;
  accel_t_gyro_union accel_t_gyro;


  //Serial.println(F(""));
  //Serial.println(F("MPU-9150"));

  // Read the raw values.
  // Read 14 bytes at once, 
  // containing acceleration, temperature and gyro.
  // With the default settings of the MPU-9150,
  // there is no filter enabled, and the values
  // are not very stable.
  error = MPU9150_read (MPU9150_ACCEL_XOUT_H, (uint8_t *) &accel_t_gyro, sizeof(accel_t_gyro));
  //Serial.print(F("Read accel, temp and gyro, error = "));
  //Serial.println(error,DEC);


  // Swap all high and low bytes.
  // After this, the registers values are swapped, 
  // so the structure name like x_accel_l does no 
  // longer contain the lower byte.
  uint8_t swap;
  #define SWAP(x,y) swap = x; x = y; y = swap

  SWAP (accel_t_gyro.reg.x_accel_h, accel_t_gyro.reg.x_accel_l);
  SWAP (accel_t_gyro.reg.y_accel_h, accel_t_gyro.reg.y_accel_l);
  SWAP (accel_t_gyro.reg.z_accel_h, accel_t_gyro.reg.z_accel_l);
  SWAP (accel_t_gyro.reg.t_h, accel_t_gyro.reg.t_l);
  SWAP (accel_t_gyro.reg.x_gyro_h, accel_t_gyro.reg.x_gyro_l);
  SWAP (accel_t_gyro.reg.y_gyro_h, accel_t_gyro.reg.y_gyro_l);
  SWAP (accel_t_gyro.reg.z_gyro_h, accel_t_gyro.reg.z_gyro_l);


  // Print the raw acceleration values

  //Serial.print(F("accel x,y,z: "));
  //Serial.print(accel_t_gyro.value.x_accel, DEC);
  //Serial.print(F(", "));
  //Serial.print(accel_t_gyro.value.y_accel, DEC);
  //Serial.print(F(", "));
  //Serial.print(accel_t_gyro.value.z_accel, DEC);
  //Serial.println(F(""));


  // The temperature sensor is -40 to +85 degrees Celsius.
  // It is a signed integer.
  // According to the datasheet: 
  //   340 per degrees Celsius, -512 at 35 degrees.
  // At 0 degrees: -512 - (340 * 35) = -12412

  //Serial.print(F("temperature: "));
  dT = ( (double) accel_t_gyro.value.temperature + 12412.0) / 340.0;
  //Serial.print(dT, 3);
  //Serial.print(F(" degrees Celsius"));
  //Serial.println(F(""));


  // Print the raw gyro values.

  //Serial.print(F("gyro x,y,z : "));
  //Serial.print(accel_t_gyro.value.x_gyro, DEC);
  //Serial.print(F(", "));
  //Serial.print(accel_t_gyro.value.y_gyro, DEC);
  //Serial.print(F(", "));
  //Serial.print(accel_t_gyro.value.z_gyro, DEC);
  //Serial.print(F(", "));
  //Serial.println(F(""));
  //delay(700);
  
    readGyro();
    triggerlevel.up = 5400;  
    triggerlevel.down = 5400;
    triggerlevel.left = 9300;
    triggerlevel.right = 8300;    
    triggerlevel.forward = 16627;
    triggerlevel.backward = 1470;
   if (accel_t_gyro.value.y_accel > triggerlevel.forward) //forward
    {
    cntr4++;      //Heart
   if (cntr4>63) cntr4=0;
   color=4;
   drawPixel(1+cntr4,4);
   drawPixel(1+cntr4,5);
   drawPixel(1+cntr4,6);
   drawPixel(1+cntr4,7);
   drawPixel(2+cntr4,3);
   drawPixel(2+cntr4,4);
   drawPixel(2+cntr4,5);
   drawPixel(2+cntr4,6);
   drawPixel(2+cntr4,7);
   drawPixel(2+cntr4,8);
   drawPixel(3+cntr4,2);
   drawPixel(3+cntr4,3);
   drawPixel(3+cntr4,4);
   drawPixel(3+cntr4,5);
   drawPixel(3+cntr4,6);
   drawPixel(3+cntr4,7);
   drawPixel(3+cntr4,8);
   drawPixel(4+cntr4,1);
   drawPixel(4+cntr4,2);
   drawPixel(4+cntr4,3);
   drawPixel(4+cntr4,4);
   drawPixel(4+cntr4,5);
   drawPixel(4+cntr4,6);
   drawPixel(4+cntr4,7);
   drawPixel(5+cntr4,1);
   drawPixel(5+cntr4,2);
   drawPixel(5+cntr4,3);
   drawPixel(5+cntr4,4);
   drawPixel(5+cntr4,5);
   drawPixel(5+cntr4,6);
   drawPixel(5+cntr4,7);
   drawPixel(6+cntr4,2);
   drawPixel(6+cntr4,3);
   drawPixel(6+cntr4,4);
   drawPixel(6+cntr4,5);
   color=7;
   drawPixel(6+cntr4,6);
   color=4;
   drawPixel(6+cntr4,7);
   drawPixel(6+cntr4,8);
   drawPixel(2+cntr4,3);
   drawPixel(7+cntr4,4);
   drawPixel(7+cntr4,5);
   color=7;
   drawPixel(7+cntr4,6);
   drawPixel(7+cntr4,7);
   color=4;
   drawPixel(7+cntr4,8);
   drawPixel(8+cntr4,4);
   drawPixel(8+cntr4,5);
   drawPixel(8+cntr4,6);
   drawPixel(8+cntr4,7);
   
   delay(47);
   vClear();
    }
   
 if (accel_t_gyro.value.x_accel < triggerlevel.backward) //backward
   {
      
   cntr3++;      //Heart
   if (cntr3>63) cntr3=0;
   color=1;
   drawPixel(1+cntr3,4);
   drawPixel(1+cntr3,5);
   drawPixel(1+cntr3,6);
   drawPixel(1+cntr3,7);
   drawPixel(2+cntr3,3);
   drawPixel(2+cntr3,4);
   drawPixel(2+cntr3,5);
   drawPixel(2+cntr3,6);
   drawPixel(2+cntr3,7);
   drawPixel(2+cntr3,8);
   drawPixel(3+cntr3,2);
   drawPixel(3+cntr3,3);
   drawPixel(3+cntr3,4);
   drawPixel(3+cntr3,5);
   drawPixel(3+cntr3,6);
   drawPixel(3+cntr3,7);
   drawPixel(3+cntr3,8);
   drawPixel(4+cntr3,1);
   drawPixel(4+cntr3,2);
   drawPixel(4+cntr3,3);
   drawPixel(4+cntr3,4);
   drawPixel(4+cntr3,5);
   drawPixel(4+cntr3,6);
   drawPixel(4+cntr3,7);
   drawPixel(5+cntr3,1);
   drawPixel(5+cntr3,2);
   drawPixel(5+cntr3,3);
   drawPixel(5+cntr3,4);
   drawPixel(5+cntr3,5);
   drawPixel(5+cntr3,6);
   drawPixel(5+cntr3,7);
   drawPixel(6+cntr3,2);
   drawPixel(6+cntr3,3);
   drawPixel(6+cntr3,4);
   drawPixel(6+cntr3,5);
   color=7;
   drawPixel(6+cntr3,6);
   color=1;
   drawPixel(6+cntr3,7);
   drawPixel(6+cntr3,8);
   drawPixel(2+cntr3,3);
   drawPixel(7+cntr3,4);
   drawPixel(7+cntr3,5);
   color=7;
   drawPixel(7+cntr3,6);
   drawPixel(7+cntr3,7);
   color=1;
   drawPixel(7+cntr3,8);
   drawPixel(8+cntr3,4);
   drawPixel(8+cntr3,5);
   drawPixel(8+cntr3,6);
   drawPixel(8+cntr3,7);
   
   Transfer();
   delay(77);
   vClear();
    }
 if (accel_t_gyro.value.z_gyro < -triggerlevel.left) //left
    {
     MPU9150_write_reg (MPU9150_PWR_MGMT_1, 0);
     SPI.setDataMode(SPI_MODE1);
     SPI.setClockDivider(SPI_CLOCK_DIV64);
     SPI.begin();
  
     pinMode(chipSelectPin, OUTPUT);
  
     vClear();
      point=!point;
   scrollString(l, point);
      Transfer();
   delay(100);
   vClear();
    }
 if ((accel_t_gyro.value.z_gyro > triggerlevel.right))  //right
    {
     MPU9150_write_reg (MPU9150_PWR_MGMT_1, 0);
     SPI.setDataMode(SPI_MODE1);
     SPI.setClockDivider(SPI_CLOCK_DIV64);
     SPI.begin();
  
     pinMode(chipSelectPin, OUTPUT);
  
     vClear();
   point=!point;
   scrollString(r, point);
   Transfer();
   delay(100);
   vClear();
   }
 /*if (accel_t_gyro.value.x_gyro > triggerlevel.up)  //up
  {
   cntr4++;                               //draw forward
   color=4;
   if (cntr4>44) cntr4=0;
   drawLine(3+cntr4,1,3+cntr4,7);
   drawLine(2+cntr4,1,2+cntr4,8);
   drawLine(1+cntr4,1,1+cntr4,7);
   drawPixel(0+cntr4,6);
   drawPixel(4+cntr4,6);
   drawPixel(5+cntr4,5);
   drawPixel(-1+cntr4,5);
   Transfer();
   delay(27);
   vClear();
    }   
 if (accel_t_gyro.value.x_gyro < -triggerlevel.down) //down
 {
   cntr3++;                               //draw stop
   color=1;
   if (cntr3>83) cntr3=0;
   drawCircle(1+cntr3,5,3);
   drawCircle(1+cntr3,4,3);
   drawCircle(1+cntr3,3,2);
   drawCircle(1+cntr3,2,1);
   drawCircle(2+cntr3,2,1);
   drawCircle(2+cntr3,5,1);
   drawCircle(1+cntr3,5,1);
   drawCircle(1+cntr3,9,1);
   drawLine(0+cntr3,2, 0+cntr3,7);
   drawLine(-1+cntr3,3, -1+cntr3,6);
   color=7;
   drawPixel(1+cntr3,7);
   drawPixel(1+cntr3,6);
   drawPixel(1+cntr3,5);
   drawPixel(1+cntr3,3); 
   Transfer();
   delay(27);
   vClear();
    }   */
}
