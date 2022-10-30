#include "services/controller.h"
#include "global.h"

int Controller::GetState() {
	return STATE;
}

void Controller::SetState(int newState) {
	STATE = newState;
}

Controller::Controller() {
	STATE = INIT;
}

int l_N_YEL_DURATION = N_YEL_DURATION;
int l_N_GRN_DURATION = N_GRN_DURATION;

void Controller::Work() {
	switch (GetState()) {
	case INIT:
		north.Switch(RED);
		west.Switch(GREEN);
		/*
		 * North RED
		 * West GREEN
		 */
		timerTraffic.Set(N_GRN_DURATION);

		/* Setting the countdown 7SEG */
		north.SetCountdown(N_RED_DURATION / 1000);
		south.SetCountdown(N_RED_DURATION / 1000);

		west.SetCountdown(N_GRN_DURATION / 1000);
		east.SetCountdown(N_GRN_DURATION / 1000);

		/* Refresh the countdown */
		if (secondTimer.HasSignal()) {
			north.RefreshCountdown();
			south.RefreshCountdown();
			west.RefreshCountdown();
			east.RefreshCountdown();
		}

		/* Check button */
		if (buttonChangeMode.IsPressed()) {
			north.Switch(YELLOW);
			west.Switch(YELLOW);
			timerTraffic.Reset();
			l_N_YEL_DURATION = N_YEL_DURATION;
			SetState(MODE_CHANGE_YEL);
		}

		if (timerTraffic.HasSignal()) {
			SetState(N_RED_W_YEL);
		}
		break;
	case N_GRN_W_RED:
		north.Switch(GREEN);
		west.Switch(RED);
		/*
		 * North GREEN
		 * West RED
		 */
		timerTraffic.Set(N_GRN_DURATION);

		/* Setting the countdown 7SEG */
		north.SetCountdown(N_GRN_DURATION / 1000);
		south.SetCountdown(N_GRN_DURATION / 1000);

		west.SetCountdown(N_RED_DURATION / 1000);
		east.SetCountdown(N_RED_DURATION / 1000);

		/* Refresh the countdown */
		if (secondTimer.HasSignal()) {
			north.RefreshCountdown();
			south.RefreshCountdown();
			west.RefreshCountdown();
			east.RefreshCountdown();
		}

		/* Check button */
		if (buttonChangeMode.IsPressed()) {
			north.Switch(YELLOW);
			west.Switch(YELLOW);
			l_N_YEL_DURATION = N_YEL_DURATION;
			SetState(MODE_CHANGE_YEL);
		}

		if (timerTraffic.HasSignal()) {
			SetState(N_YEL_W_RED);
		}
		break;
	case N_YEL_W_RED:
		north.Switch(YELLOW);
		west.Switch(RED);
		/*
		 * North YELLOW
		 * West RED
		 */
		timerTraffic.Set(N_YEL_DURATION);

		/* Setting the countdown 7SEG */
		north.SetCountdown(N_YEL_DURATION / 1000);
		south.SetCountdown(N_YEL_DURATION / 1000);

		west.SetCountdown(N_RED_DURATION / 1000);
		east.SetCountdown(N_RED_DURATION / 1000);

		/* Refresh the countdown */
		if (secondTimer.HasSignal()) {
			north.RefreshCountdown();
			south.RefreshCountdown();
			west.RefreshCountdown();
			east.RefreshCountdown();
		}

		/* Check button */
		if (buttonChangeMode.IsPressed()) {
			north.Switch(YELLOW);
			west.Switch(YELLOW);
			l_N_YEL_DURATION = N_YEL_DURATION;
			SetState(MODE_CHANGE_YEL);
		}

		if (timerTraffic.HasSignal()) {
			SetState(N_RED_W_GRN);
		}
		break;
	case N_RED_W_GRN:
		north.Switch(RED);
		west.Switch(GREEN);
		/*
		 * North RED
		 * West GREEN
		 */
		timerTraffic.Set(N_GRN_DURATION);

		/* Setting the countdown 7SEG */
		north.SetCountdown(N_RED_DURATION / 1000);
		south.SetCountdown(N_RED_DURATION / 1000);

		west.SetCountdown(N_GRN_DURATION);
		east.SetCountdown(N_GRN_DURATION);

		/* Refresh the countdown */
		if (secondTimer.HasSignal()) {
			north.RefreshCountdown();
			south.RefreshCountdown();
			west.RefreshCountdown();
			east.RefreshCountdown();
		}

		/* Check button */
		if (buttonChangeMode.IsPressed()) {
			north.Switch(YELLOW);
			west.Switch(YELLOW);
			l_N_YEL_DURATION = N_YEL_DURATION;
			SetState(MODE_CHANGE_YEL);
		}

		if (timerTraffic.HasSignal()) {
			SetState(N_RED_W_YEL);
		}
		break;
	case N_RED_W_YEL:
		north.Switch(RED);
		west.Switch(YELLOW);
		/*
		 * North RED
		 * West YELLOW
		 */
		timerTraffic.Set(N_YEL_DURATION);

		/* Setting the countdown 7SEG */
		north.SetCountdown(N_RED_DURATION / 1000);
		south.SetCountdown(N_RED_DURATION / 1000);

		west.SetCountdown(N_YEL_DURATION / 1000);
		east.SetCountdown(N_YEL_DURATION / 1000);

		/* Refresh the countdown */
		if (secondTimer.HasSignal()) {
			north.RefreshCountdown();
			south.RefreshCountdown();
			west.RefreshCountdown();
			east.RefreshCountdown();
		}

		/* Check button */
		if (buttonChangeMode.IsPressed()) {
			north.Switch(YELLOW);
			west.Switch(YELLOW);
			l_N_YEL_DURATION = N_YEL_DURATION;
			SetState(MODE_CHANGE_YEL);
		}

		if (timerTraffic.HasSignal()) {
			SetState(N_GRN_W_RED);
		}
		break;
	case MODE_CHANGE_YEL:
		/*
		 * Blinks YELLOW
		 * Use NORTH & WEST SegmentLed
		 * buttonIncreaseTime increase time duration of YELLOW
		 * buttonSet accept changes and return to normal mode
		 */
		south.DisableCountdown();
		east.DisableCountdown();
		north.Display(l_N_YEL_DURATION / 1000);
		west.Display(l_N_YEL_DURATION / 10000);

		timerTraffic.Set(500);

		/* Move to Yellow mode */
		if (buttonChangeMode.IsPressed()) {
			north.Switch(GREEN);
			west.Switch(GREEN);
			l_N_GRN_DURATION = N_GRN_DURATION;
			SetState(MODE_CHANGE_GRN);
		}

		/* Increment local value */
		if (buttonIncreaseTime.IsPressed()) {
			l_N_YEL_DURATION += 1000;
			if (l_N_YEL_DURATION > 99000) {
				l_N_YEL_DURATION = 1000;
			}
			north.Display(l_N_GRN_DURATION / 1000);
			west.Display(l_N_GRN_DURATION / 10000);
		}

		/* Save changes */
		if (buttonSet.IsPressed()) {
			N_YEL_DURATION = l_N_YEL_DURATION;
			SetState(N_RED_W_GRN);
		}

		if (timerTraffic.HasSignal()) {
			north.Toggle(YELLOW);
			west.Toggle(YELLOW);
		}

		break;
	case MODE_CHANGE_GRN:
		/*
		 * Blinks GREEN
		 * Use NORTH & WEST SegmentLed
		 * buttonIncreaseTime increase time duration of YELLOW
		 * buttonSet accept changes and return to normal mode
		 */
		south.DisableCountdown();
		east.DisableCountdown();
		north.Display(l_N_GRN_DURATION / 1000);
		west.Display(l_N_GRN_DURATION / 10000);

		timerTraffic.Set(500);

		/* Move to normal mode */
		if (buttonChangeMode.IsPressed()) {
			SetState(N_RED_W_GRN);
		}

		/* Increment local value */
		if (buttonIncreaseTime.IsPressed()) {
			l_N_GRN_DURATION += 1000;
			if (l_N_GRN_DURATION > 99000) {
				l_N_GRN_DURATION = 1000;
			}
			north.Display(l_N_GRN_DURATION / 1000);
			west.Display(l_N_GRN_DURATION / 10000);
		}

		/* Save changes */
		if (buttonSet.IsPressed()) {
			N_GRN_DURATION = l_N_GRN_DURATION;
			timerTraffic.Reset();
			SetState(N_RED_W_GRN);
		}

		if (timerTraffic.HasSignal()) {
			north.Toggle(GREEN);
			west.Toggle(GREEN);
		}

		break;
	}
}
