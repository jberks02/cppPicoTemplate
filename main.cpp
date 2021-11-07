/*
 * picoCPP for Raspberry Pi Pico
 *
 * @version     1.0.0
 * @author      Justin Berkshire
 * @copyright   2021
 * @licence     MIT
 *
 */

#include "main.h"

int main()
{
    const uint LED = PICO_DEFAULT_LED_PIN;

    gpio_init(LED);

    gpio_set_dir(LED, GPIO_OUT);

    while (true)
    {
        gpio_put(LED, 1);
        sleep_ms(1000);
        gpio_put(LED, 0);
        sleep_ms(1000);
    }

    return 0;
}
