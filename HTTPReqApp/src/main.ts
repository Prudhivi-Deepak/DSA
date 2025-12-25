import { bootstrapApplication } from '@angular/platform-browser';

import { AppComponent } from './app/app.component';
import { HttpEventType, HttpHandler, HttpHandlerFn, HttpRequest, provideHttpClient, withInterceptors } from '@angular/common/http';
import { tap } from 'rxjs/internal/operators/tap';

function LoggingInterceptor(request: HttpRequest<unknown>, next: HttpHandlerFn) {
    console.log('Outgoing request', request);
    // const req = request.clone({
    //     headers: request.headers.set('X-Custom-Header', 'MyCustomHeaderValue')
    // });
    return next(request).pipe(
        tap({
            next: event=>{
                if(event.type == HttpEventType.Response){
                    console.log("Incoming response");
                    console.log(event.body);
                    console.log(event.type);
                }
            }
        })
    )
}


bootstrapApplication(AppComponent, {
    providers: [provideHttpClient(
        withInterceptors([LoggingInterceptor])
    )]
}).catch((err) => console.error(err));
