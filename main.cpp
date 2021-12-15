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

    stdio_init_all();

    while (true)
    {
        printf("deadly virus");
        gpio_put(LED, 1);
        sleep_ms(500);
        gpio_put(LED, 0);
        sleep_ms(500);
    }

    return 0;
}
