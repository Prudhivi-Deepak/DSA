import { Pipe, PipeTransform } from "@angular/core";
@Pipe({
    name: 'temperature', //not an optional configuration--> it's a must
    standalone: true
})
export class TemperaturePipe implements PipeTransform {

    // transform(value: string | number, ...args: any[]){
    transform(value: string | number | null, inputType: 'celsius' | 'fahrenheit', outputType: 'celsius' | 'fahrenheit') {
        let inputValue: number;

        if(value === null) {
            return '';
        }

        if (typeof value === 'string') {
            inputValue = parseFloat(value);
        } else {
            inputValue = value;
        }

        let outputValue: number;

        if (inputType === 'celsius' && outputType === 'fahrenheit') {
            outputValue = (inputValue * 9 / 5) + 32;
        } else if (inputType === 'fahrenheit' && outputType === 'celsius') {
            outputValue = (inputValue - 32) * 5 / 9;
        }
        else {
            outputValue = inputValue;
        }

        let symbol: '°C' | '°F';

        if (outputType) {
            symbol = inputType === 'celsius' ? '°F' : '°C';
        } else {
            symbol = inputType === 'celsius' ? '°F' : '°C';
        }

        // return `${outputValue} ${symbol}`;
        return `${outputValue.toFixed(2)} ${symbol}`;
    }
}