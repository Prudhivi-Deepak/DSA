import { Directive, ElementRef, inject, input } from "@angular/core";


@Directive({
    selector: "[appSafeLink]", //optional attribute selector so it can be added as an attribute to any element
    // standalone: true
    host: {
        '(click)': 'onClick($event)'
    }
})
export class SafeLinkDirective {
    // Directive implementation goes here
    constructor() {
        console.log("SafeLinkDirective initialized");
    }

    eventfrom = input('from-my-app', {alias: 'appSafeLink'});
    // eventfrom = input('from-my-app');

    hostElement = inject<ElementRef<HTMLAnchorElement>>(ElementRef);

    onClick(event: MouseEvent) {
        console.log("SafeLinkDirective clicked");
        const wantsToLeave = window.confirm("This link is safe to click!");
        if (!wantsToLeave) {
            // Prevent default action
            event.preventDefault(); return;
        }

        // const address = (event.target as HTMLAnchorElement).href;
        const address = this.hostElement.nativeElement.href;
        // (event.target as HTMLAnchorElement).href = address + "?from=my-app";
        // (event.target as HTMLAnchorElement).href = address + "?from=" + this.eventfrom();
        this.hostElement.nativeElement.href = address + "?from=" + this.eventfrom();
    }

}