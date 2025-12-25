import { Component, DestroyRef, inject, Pipe, signal } from '@angular/core';

import { Place } from '../place.model';
import { PlacesComponent } from '../places.component';
import { PlacesContainerComponent } from '../places-container/places-container.component';
import { HttpClient } from '@angular/common/http';
import { map } from 'rxjs/internal/operators/map';
import { JsonPipe } from '@angular/common';
import { throwError } from 'rxjs/internal/observable/throwError';
import { catchError } from 'rxjs/internal/operators/catchError';
import { PlacesService } from '../places.service';

@Component({
  selector: 'app-available-places',
  standalone: true,
  templateUrl: './available-places.component.html',
  styleUrl: './available-places.component.css',
  imports: [PlacesComponent, PlacesContainerComponent, JsonPipe],
})
export class AvailablePlacesComponent {
  places = signal<Place[] | undefined>(undefined);
  isFetching = signal(false);
  isError = signal('');

  private httpClient = inject(HttpClient);
  private destroyerRef = inject(DestroyRef);
  private placesService = inject(PlacesService);

  ngOnInit(){
    this.isFetching.set(true);
    const httpSubscription = this.placesService.loadAvailablePlaces().subscribe({
      next: (event)=>{
        console.log(event);
        // this.places.set(event.body?.places);
        this.places.set(event);
      },
      complete: ()=>{
        this.isFetching.set(false); 
      },
      error: (error)=>{
        this.isFetching.set(false);
        this.isError.set(error.message);
      }
    });

    this.destroyerRef.onDestroy(() => {
        httpSubscription.unsubscribe();
    })
  }

  onSelectedPlace(place: Place) {
    console.log('Selected place: ', place);

    this.placesService.addPlaceToUserPlaces(place).subscribe({
      next: (response)=>{
        console.log(response);
      }
    });
  }


}
