#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED_PIN 2      // Pino do LED

int main(void)
{
    const struct device *gpio = DEVICE_DT_GET(DT_NODELABEL(gpio0));    
    // Configura o pino do LED como saída
    gpio_pin_configure(gpio, LED_PIN, GPIO_OUTPUT_INACTIVE);

	printf("Configuração inicial do projeto arm robot");

	while(1){
		
        gpio_pin_set(gpio, LED_PIN, 1);  // Acende o LED
		k_msleep(1000);
        gpio_pin_set(gpio, LED_PIN, 0);  // Apaga o LED
        k_msleep(1000);  // Pequeno delay para debounce
	}

	return 0;
}
