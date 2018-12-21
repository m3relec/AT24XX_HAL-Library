//AT24XX Function for Read and Write
//smartelc.ir

void ee_write(uint16_t ee_add, uint16_t add, uint8_t data)
{
  uint8_t ee_w[3];
  HAL_Delay(5);
  ee_w[0]=(add>>8);
  ee_w[1]=add;
  ee_w[2]=data;
  HAL_I2C_Master_Transmit(&hi2c1, ee_add, ee_w, 3, 1);
}

uint8_t ee_read(uint16_t ee_add, uint16_t add)
{
  uint8_t ee_r[2],read;
  HAL_Delay(5);
  ee_r[0]=(add>>8);
  ee_r[1]=add;
  HAL_I2C_Master_Transmit(&hi2c1, ee_add, ee_r, 2, 1);
  HAL_Delay(50);
  HAL_I2C_Master_Receive(&hi2c1, ee_add, &read, 1, 1);
  return read;
}