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
  selector: 'app-user-places',
  standalone: true,
  templateUrl: './user-places.component.html',
  styleUrl: './user-places.component.css',
  imports: [PlacesContainerComponent, PlacesComponent],
})
export class UserPlacesComponent {

  // favaoritePlaces = signal<Place[] | undefined>(undefined);
  isFetching = signal(false);
  isError = signal('');

  private httpClient = inject(HttpClient);
  private destroyerRef = inject(DestroyRef);
  private placesService = inject(PlacesService);

  favaoritePlaces = this.placesService.loadedUserPlaces;

  ngOnInit() {
    this.isFetching.set(true);
    const httpSubscription = this.placesService.loadUserPlaces().subscribe({
      // next: (event) => {
      //   console.log(event);
      //   // this.places.set(event.body?.places);
      //   this.favaoritePlaces.set(event);

      // },
      complete: () => {
        this.isFetching.set(false);
      },
      error: (error) => {
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

    this.placesService.removeUserPlace(place).subscribe({
      // ne
      complete: () => {
        this.isFetching.set(false);
      },
      error: (error) => {
        this.isFetching.set(false);
        this.isError.set(error.message);
      }
    });
  }
}
