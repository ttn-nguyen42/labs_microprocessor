#include <components/switch_button.h>

void Button::Listen() {
  this->m_KeyReg2 = this->m_KeyReg1;
  this->m_KeyReg1 = this->m_KeyReg0;
  this->m_KeyReg0 = HAL_GPIO_ReadPin(this->m_PinPair->GetPort(), this->m_PinPair->GetPin());
  if ((m_KeyReg1 == m_KeyReg0) && (m_KeyReg1 == m_KeyReg2)) {
    if (m_KeyReg2 != m_KeyReg3) {
      m_KeyReg3 = m_KeyReg2;

      if (m_KeyReg3 == 0) {
        c_Timeout = 500;
        this->m_Flag = true;
        if (m_Callback != nullptr) {
        	m_Callback();
        }
      }
    } else {
      c_Timeout -= 1;
      if (c_Timeout == 0) {
        m_KeyReg3 =1;
      }
    }
  }
}

bool Button::IsPressed() {
  if (this->m_Flag == true) {
    this->m_Flag = false;
    return true;
  }
  return false;
}
