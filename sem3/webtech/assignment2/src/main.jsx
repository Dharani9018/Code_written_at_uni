import React, { useEffect, useState } from 'react';
import axios from 'axios';
import { createRoot } from 'react-dom/client';

export default function App() {
  const [position, setPosition] = useState(null);
  const [locError, setLocError] = useState(null);

  const [weather, setWeather] = useState(null);
  const [weatherLoading, setWeatherLoading] = useState(false);
  const [weatherError, setWeatherError] = useState(null);

  const [plan, setPlan] = useState({
    traveler: 'Alex',
    start: '2025-10-10',
    destinations: ['Paris', 'London'],
  });
  const [newDest, setNewDest] = useState('');

  const bookingXML = `<?xml version="1.0" encoding="UTF-8"?>
<booking>
  <id>BK-2025-001</id>
  <traveler>
    <name>Alex</name>
    <email>alex@example.com</email>
  </traveler>
  <itinerary>
    <destination>
      <city>Paris</city>
      <date>2025-10-12</date>
    </destination>
    <destination>
      <city>London</city>
      <date>2025-10-15</date>
    </destination>
  </itinerary>
</booking>`;
  const [convertedJson, setConvertedJson] = useState(null);

  function fetchLocation() {
    setLocError(null);
    setPosition(null);
    if (!navigator.geolocation) {
      setLocError('Geolocation not supported.');
      return;
    }

    navigator.geolocation.getCurrentPosition(
      (pos) => {
        setPosition({
          latitude: pos.coords.latitude,
          longitude: pos.coords.longitude,
          accuracy: pos.coords.accuracy,
        });
      },
      (err) => setLocError(err.message || 'Failed to get location.'),
      { timeout: 10000 }
    );
  }

  useEffect(() => {
    async function fetchWeather(lat, lon) {
      setWeather(null);
      setWeatherError(null);
      setWeatherLoading(true);
      try {
        const url = `https://api.open-meteo.com/v1/forecast?latitude=${lat}&longitude=${lon}&current_weather=true`;
        const res = await axios.get(url);
        setWeather(res.data.current_weather || null);
      } catch (e) {
        setWeatherError('Could not fetch weather');
      } finally {
        setWeatherLoading(false);
      }
    }

    if (position) {
      fetchWeather(position.latitude, position.longitude);
    }
  }, [position]);

  function addDestination() {
    if (!newDest.trim()) return;
    setPlan((p) => ({ ...p, destinations: [...p.destinations, newDest.trim()] }));
    setNewDest('');
  }

  function convertXmlToJson() {
    try {
      const parser = new DOMParser();
      const xml = parser.parseFromString(bookingXML, 'application/xml');
      function xmlToObj(node) {
        // text node
        if (node.nodeType === 3) return node.nodeValue.trim();
        const obj = {};
        const children = Array.from(node.childNodes).filter((n) => n.nodeType === 1 || (n.nodeType === 3 && n.nodeValue.trim()));
        if (children.length === 0) return null;
        children.forEach((child) => {
          if (child.nodeType === 3) {
            // text node
            const v = child.nodeValue.trim();
            if (v) return v;
          }
          const name = child.nodeName;
          const val = xmlToObj(child);
          if (obj[name]) {
            if (!Array.isArray(obj[name])) obj[name] = [obj[name]];
            obj[name].push(val);
          } else {
            obj[name] = val;
          }
        });
        return obj;
      }
      const root = xml.documentElement;
      const out = { [root.nodeName]: xmlToObj(root) };
      setConvertedJson(out);
    } catch (e) {
      setConvertedJson({ error: 'Parsing failed' });
    }
  }

  const styles = {
    container: { fontFamily: 'Arial, Helvetica, sans-serif', padding: 16, background: '#f3f6fb', minHeight: '100vh' },
    header: { maxWidth: 1000, margin: '0 auto 16px' },
    main: { maxWidth: 1000, margin: '0 auto', display: 'grid', gap: 16, gridTemplateColumns: '1fr', },
    card: { background: '#fff', padding: 12, borderRadius: 8, boxShadow: '0 2px 8px rgba(0,0,0,0.06)' },
    row: { display: 'grid', gridTemplateColumns: '1fr 1fr', gap: 16 },
    pre: { background: '#f5f7fa', padding: 8, borderRadius: 6, overflow: 'auto' },
    input: { padding: 8, borderRadius: 4, border: '1px solid #cbd5e1' },
    btn: { padding: '8px 12px', borderRadius: 6, border: 'none', cursor: 'pointer' },
  };

  return (
    <div style={styles.container}>
      <header style={styles.header}>
        <h1 style={{ margin: 0 }}>Smart Travel Companion Dashboard</h1>
        <p style={{ margin: '6px 0 0', color: '#374151' }}>Media, Geolocation, Weather, Travel Plan and XML→JSON conversion.</p>
      </header>

      <main style={{ ...styles.main, gridTemplateColumns: '1fr', gap: 16 }}>
        <div style={styles.card}>
          <h3>Travel Media</h3>
          <div>
            <video controls style={{ width: '100%', maxHeight: 360 }}>
              <source src="video.mp4" type="video/mp4" />
              Your browser does not support video tag.
            </video>
          </div>
        </div>

        <div style={{ display: 'grid', gridTemplateColumns: '1fr 1fr', gap: 16 }}>
          <div style={styles.card}>
            <h3>Current Location</h3>
            <button
              style={{ ...styles.btn, background: '#2563eb', color: '#fff' }}
              onClick={fetchLocation}
            >
              Get Location
            </button>
            <div style={{ marginTop: 8 }}>
              {locError && <div style={{ color: 'red' }}>Error: {locError}</div>}
              {position ? (
                <div>
                  <div>Latitude: {position.latitude.toFixed(6)}</div>
                  <div>Longitude: {position.longitude.toFixed(6)}</div>
                  <div>Accuracy: {position.accuracy} m</div>
                </div>
              ) : (!locError && <div style={{ color: '#6b7280' }}>No position yet.</div>)}
            </div>
          </div>

          <div style={styles.card}>
            <h3>Live Weather Lookup</h3>
            <div style={{ marginTop: 6 }}>
              <div style={{ color: '#6b7280' }}>Weather loads after you fetch location.</div>
              {weatherLoading && <div>Loading weather...</div>}
              {weatherError && <div style={{ color: 'red' }}>{weatherError}</div>}
              {weather && (
                <div>
                  <div>Temperature: {weather.temperature} °C</div>
                  <div>Wind Speed: {weather.windspeed} m/s</div>
                  <div>Wind Direction: {weather.winddirection}°</div>
                  <div>Time (UTC): {weather.time}</div>
                </div>
              )}
            </div>
          </div>
        </div>

        <div style={styles.card}>
          <h3>Travel Plan Data (JSON)</h3>
          <pre style={styles.pre}>{JSON.stringify(plan, null, 2)}</pre>
          <div style={{ display: 'flex', gap: 8, marginTop: 8 }}>
            <input
              value={newDest}
              onChange={(e) => setNewDest(e.target.value)}
              placeholder="Add destination (e.g. Rome)"
              style={{ ...styles.input, flex: 1 }}
              onKeyDown={(e) => { if (e.key === 'Enter') addDestination(); }}
            />
            <button style={{ ...styles.btn, background: '#10b981', color: '#fff' }} onClick={addDestination}>Add</button>
          </div>
        </div>

        <div style={{ ...styles.card }}>
          <h3>Convert Booking XML → JSON</h3>
          <textarea readOnly defaultValue={bookingXML} style={{ width: '100%', height: 120, padding: 8 }} />
          <div style={{ marginTop: 8 }}>
            <button style={{ ...styles.btn, background: '#7c3aed', color: '#fff' }} onClick={convertXmlToJson}>Convert to JSON</button>
          </div>
          <div style={{ marginTop: 8 }}>
            <pre style={styles.pre}>{convertedJson ? JSON.stringify(convertedJson, null, 2) : 'No conversion yet.'}</pre>
          </div>
        </div>
      </main>

      <footer style={{ maxWidth: 1000, margin: '16px auto 0', color: '#6b7280', fontSize: 12 }}>Built with React Hooks • Axios • HTML5 Media • Geolocation • Open-Meteo</footer>
    </div>
  );
}

const rootEl = document.getElementById('root');
if (rootEl) {
  const root = createRoot(rootEl);
  root.render(<App />);
}
