# Informe de Retroalimentación Técnica

**Proyecto analizado:** Backend del formulario de contacto (`postCommentsChatBotServices`)  
**Analista:** N.A.L  
**Fecha:** 2025-08-20 
**Objetivo:** Documentar cómo funciona el endpoint `/tlgrm`, identificar posibles riesgos y dar recomendaciones para que no haya problemas en el futuro.

---

## 1️ Resumen rápido

Al revisar el proyecto, vi que hay un servicio que envía los datos del formulario de contacto a un endpoint `/tlgrm`. Para entender cómo funcionaba, hice algunas pruebas enviando datos de prueba directamente desde la consola del navegador.  

**Qué encontré:**

- El endpoint acepta cualquier POST sin pedir autenticación.  
- Se pueden enviar varias solicitudes consecutivas y el backend responde correctamente.  
- No hay validaciones estrictas de los datos recibidos.

Esto no es un problema crítico ahora, pero sí es un punto que podría explotarse si no se protege.

---

## 2️ Contexto del código

El servicio que maneja los datos del formulario se ve así:

```ts
export const postCommentsChatBotServices = async ({
  name,
  email,
  phone,
  moreInformation,
}: FormData) => {
  const response = await api.post("/tlgrm", {
    name,
    email,
    phone,
    moreInformation,
  });
  return response.data;
};
```

- Usa Axios para enviar los datos al backend.
- Los campos esperados son: name, email, phone y moreInformation.
- La URL base del backend es:
https://backend-portafolio-opal.vercel.app/de342e8b-2813-46d1-8a8e-4a1c41e62b72

---

## 3️ Pasos reproducibles

- Si querés probarlo vos mismo, esto es lo que hice:
- Abrí la página en Chrome.
- Abrí las Herramientas de desarrollador (F12) y luego la Consola.
- Pegá este script en la consola y presioná Enter:

```js
(async () => {
  const n = 5;
  const data = {
    name: "Test",
    email: "sitodosalebien@teestarallegandoelmail",
    phone: "si lees esto arreglalo :D",
    moreInformation: "si lo llegas a leer me escribes al numero19.lae@gmail.com",
  };

  for (let i = 1; i <= n; i++) {
    try {
      console.log(`=== Enviando petición #${i} ===`);
      const response = await fetch(
        "https://backend-portafolio-opal.vercel.app/de342e8b-2813-46d1-8a8e-4a1c41e62b72/tlgrm",
        {
          method: "POST",
          headers: { "Content-Type": "application/json" },
          body: JSON.stringify(data),
        }
      );

      console.log("Status:", response.status);
      console.log("StatusText:", response.statusText);

      try {
        const jsonData = await response.json();
        console.log("Cuerpo de la respuesta (JSON):", jsonData);
      } catch {
        const textData = await response.text();
        console.log("Cuerpo de la respuesta (Texto):", textData);
      }
    } catch (error) {
      console.error("Error al enviar la solicitud:", error);
    }

    console.log("\n----------------------------\n");
  }
})();

```

Vas a ver en la consola cada respuesta del backend y el estado de cada petición.

---

## 4️ Qué encontré

- El endpoint está expuesto: cualquiera podría enviar datos a /tlgrm.
- Acepta cualquier info: no valida si los datos tienen el formato correcto ni si son legítimos.
- Se pueden hacer envíos consecutivos: no hay límites de frecuencia.
- En resumen, el endpoint funciona, pero hay cosas que podrían mejorarse para que sea más seguro.

---

## 5️ Riesgos potenciales

- Alguien podría enviar spam o automatizar envíos al formulario.
- Datos mal formateados o maliciosos podrían entrar a la base de datos.
- Múltiples envíos podrían afectar el backend si se hacen de manera masiva.